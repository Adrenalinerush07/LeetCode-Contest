class Solution
{
public:
    int maximumScore(vector<int> &n, int k)
    {
        int mn = n[k], sc = n[k], i = k, j = k;
        do
        {
            if (i > 0 and j < n.size() - 1)
            {
                if (n[i - 1] >= n[j + 1])
                {
                    i--;
                }
                else
                {
                    j++;
                }
                // n[i-1]>=n[j+1]?i--:j++;
            }
            else if (i == 0 and j < n.size() - 1)
            {
                j++;
            }
            else if (j == n.size() - 1 and i > 0)
            {
                i--;
            }
            mn = min({mn, n[i], n[j]});
            sc = max({sc, ((j - i + 1) * mn)});
        } while (i > 0 || j < n.size() - 1);
        return sc;
    }
};