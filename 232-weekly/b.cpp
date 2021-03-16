class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        map<int, int> mp;
        for (auto i : edges)
        {
            for (auto j : i)
            {
                mp[j]++;
            }
        }
        int ans;
        for (auto i : mp)
        {
            if (i.second == mp.size() - 1)
            {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};
