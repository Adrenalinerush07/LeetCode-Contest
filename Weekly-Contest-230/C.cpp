class Solution
{
public:
    int minOperations(vector<int> &a, vector<int> &b)
    {
        int sum1 = accumulate(a.begin(), a.end(), (int)0);
        int sum2 = accumulate(b.begin(), b.end(), (int)0);
        vector<int> temp;
        if (sum2 < sum1)
        {
            temp = b;
            b = a;
            a = temp;
        }
        priority_queue<int, vector<int>, greater<int>> small;
        for (auto i : a)
        {
            small.push(i);
        }
        priority_queue<int> big;
        for (auto i : b)
        {
            big.push(i);
        }
        int diff = abs(sum2 - sum1);
        int steps = 0;
        while (small.size() and big.size() and diff)
        {
            int op1 = 6 - small.top();
            int op2 = big.top() - 1;
            if (op1 > op2)
            {
                int exe = min(op1, diff);
                steps++;
                small.pop();
                diff -= exe;
            }
            else
            {
                int exe = min(op2, diff);
                steps++;
                big.pop();
                diff -= exe;
            }
        }
        while (small.size() and diff)
        {
            int op = 6 - small.top();
            int exe = min(op, diff);
            steps++;
            small.pop();
            diff -= exe;
        }
        while (big.size() and diff)
        {
            int op = big.top() - 1;
            int exe = min(op, diff);
            steps++;
            big.pop();
            diff -= exe;
        }
        if (diff)
        {
            return -1;
        }
        return steps;
    }
};