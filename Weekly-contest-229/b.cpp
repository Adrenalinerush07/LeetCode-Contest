class Solution
{
public:
    vector<int> minOperations(string b)
    {
        int ans;
        vector<int> a(b.size(), 0);
        for (int i = 0; i < b.size(); i++)
        {
            ans = 0;
            for (int j = 0; j < b.size(); j++)
            {
                if (i != j and b[j] == '1')
                {
                    ans += abs(j - i);
                }
            }
            a[i] = ans;
        }
        return a;
    }
};