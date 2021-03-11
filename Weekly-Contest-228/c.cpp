class Solution
{
public:
    bool ok(int mid, int m, vector<int> &n)
    {
        int cnt = 0;
        for (auto i : n)
        {
            if (i > mid)
            {
                cnt += ((i / mid) - 1);
                if (i % mid != 0)
                {
                    cnt++;
                }
            }
        }
        // debug(cnt);
        return cnt <= m;
    }
    int minimumSize(vector<int> &n, int m)
    {
        int l = 1, r = *max_element(n.begin(), n.end());
        // int l = 2, r=2;
        int ans;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            // debug(mid);B

            if (ok(mid, m, n))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
        // debug(ok(2,m,n));
        // return 1;
    }
};