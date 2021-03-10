#include <bits/stdc++.h>
using namespace std;
#define int long long

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
// void __print(long long x) {cerr << x;}
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const int N = 2e5 + 4;
const int mod = 1e9 + 7;

/*



*/

class Solution
{
public:
    int dp[1001][1001];
    int recur(vector<int> &num, vector<int> &mul, int step, int l, int r)
    {
        if (step >= mul.size())
        {
            return 0;
        }
        int i = l;
        int j = num.size() - r - 1;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int op1 = num[l] * mul[step] + recur(num, mul, step + 1, l + 1, r);
        int op2 = num[r] * mul[step] + recur(num, mul, step + 1, l, r - 1);
        // debug(op1, op2, step, l, r);
        return dp[i][j] = max(op1, op2);
    }
    int maximumScore(vector<int> &num, vector<int> &mul)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = num.size();
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = -1;
            }
        }
        int step = 0, l = 0, r = num.size() - 1;
        int ans = recur(num, mul, step, l, r);
        return ans;
    }
};

void solve()
{
    vector<int> a{1, 2, 3};
    // vector<int> a{-5,-3,-3,-2,7,1};
    vector<int> b{3, 2, 1};
    // vector<int> b{-10,-5,3,4,6};

    Solution a1;
    int ans = a1.maximumScore(a, b);
    debug(ans);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    // cin>>tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}