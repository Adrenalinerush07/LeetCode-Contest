
class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {

        long long int sum = accumulate(nums.begin(), nums.end(), (long long int)0);
        long long int diff = abs(goal - sum);
        long long int d = diff / limit;
        long long int rem = diff % limit;
        if (rem)
        {
            d++;
        }
        return d;
    }
};