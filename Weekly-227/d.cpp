class Solution
{
public:
    vector<int> gen_sum(vector<int> &h)
    {
        vector<int> t;
        // debug(h);
        // cout<<(1<<h.size())<<endl;
        for (int i = 0; i < 1 << h.size(); i++)
        {
            // debug("ds");
            int sum = 0;
            for (int j = 0; j < h.size(); j++)
            {
                if ((1 << j) & i)
                {
                    sum += h[j];
                }
            }
            t.push_back(sum);
        }
        return t;
    }
    int minAbsDifference(vector<int> &nums, int goal)
    {
        vector<int> half1, half2;
        int i;
        for (i = 0; i < nums.size() / 2; i++)
        {
            half1.push_back(nums[i]);
        }
        for (; i < nums.size(); i++)
        {
            half2.push_back(nums[i]);
        }
        vector<int> a = gen_sum(half1);
        vector<int> b = gen_sum(half2);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // cout<<"Elements of a=->"<<endl;
        // for(auto i:a){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<"Elements of b=->"<<endl;
        // for(auto i:b){
        // cout<<i<<" ";
        // }
        // cout<<endl;
        int ans = INT_MAX;
        for (auto i : a)
        {
            auto rem = lower_bound(b.begin(), b.end(), (goal - i)) - b.begin();
            if (rem > 0)
            {
                ans = min(ans, abs(goal - (i + b[rem - 1])));
            }
            if (rem < b.size())
            {
                ans = min(ans, abs(goal - (i + b[rem])));
            }
        }

        return ans;
    }
};