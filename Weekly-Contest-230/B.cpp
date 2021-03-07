class Solution
{
public:
    int optimal(int a, int b, int tar)
    {
        int op1 = abs(tar - a);
        int op2 = abs(tar - b);
        if (op1 < op2)
        {
            return a;
        }
        else if (op2 < op1)
        {
            return b;
        }
        else
        {
            return a < b ? a : b;
        }
    }
    int fun(vector<int> toppingCosts, int i, int tar, int sum)
    {
        if (i >= toppingCosts.size())
        {
            return sum;
        }
        int a = fun(toppingCosts, i + 1, tar, sum + toppingCosts[i]);
        int b = fun(toppingCosts, i + 1, tar, sum + (toppingCosts[i] * 2));
        int c = fun(toppingCosts, i + 1, tar, sum);
        int temp = optimal(a, optimal(b, c, tar), tar);
        return temp;
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        int ans = 1e9;
        for (auto i : baseCosts)
        {
            int temp = fun(toppingCosts, 0, target, i);
            ans = optimal(ans, temp, target);
        }
        return ans;
    }
};