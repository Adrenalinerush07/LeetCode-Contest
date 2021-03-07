class Solution
{
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        int sz = toppingCosts.size();
        for (int i = 0; i < sz; i++)
        {
            toppingCosts.push_back(toppingCosts[i]);
        }
        int ans = 1e9;
        int cur = 1e9;
        for (int i = 0; i < baseCosts.size(); i++)
        {
            int cost = baseCosts[i];
            for (int j = 0; j < (1 << toppingCosts.size()); j++)
            {
                for (int k = 0; k < toppingCosts.size(); k++)
                {
                    if (j & (1 << k))
                    {
                        cost += toppingCosts[k];
                    }
                }
                if (abs(target - cost) < cur)
                {
                    // cout<<"lol "<<ans<<" "<<cost<<" "<<cur<<endl;
                    ans = cost;
                    cur = abs(target - cost);
                }
                else if (abs(target - cost) == cur)
                {
                    // cout<<"gotta->"<<endl;
                    if (cost < ans)
                    {
                        ans = cost;
                    }
                }
                // debug(cost,cur,ans);
                cost = baseCosts[i];
            }
        }
        return ans;
    }
};
