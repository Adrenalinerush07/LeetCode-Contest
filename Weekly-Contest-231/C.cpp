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
    int dis[20001];
    int dp[20001];
    int M = 1e9 + 7;
    void dijkatras(int n, vector<pair<int, int>> adlist[])
    {
        vector<int> vis(n + 1, -1);

        vis[n] = 1;
        dis[n] = 0;
        set<pair<int, int>> pq;
        pq.insert({0, n});

        while (pq.empty() == false)
        {
            auto it = *(pq.begin());
            pq.erase(pq.begin());

            for (auto i : adlist[it.second])
            {
                if (dis[i.first] > dis[it.second] + i.second)
                {
                    auto ptr = pq.find(make_pair(dis[i.first], i.first));

                    if (ptr != pq.end())
                        pq.erase(ptr);

                    dis[i.first] = dis[it.second] + i.second;
                    pq.insert({dis[i.first], i.first});
                }
            }
        }
    }

    int dfs(int n, vector<pair<int, int>> adlist[], int d)
    {
        if (n == 1)
            return 1;

        int ans = 0;

        if (dp[n] != -1)
            return dp[n];

        for (auto i : adlist[n])
        {
            if (d < dis[i.first])
            {
                ans = (ans % M + dfs(i.first, adlist, dis[i.first]) % M) % M; //distanceToLastNode(zi) > distanceToLastNode(zi+1) condition
            }
        }
        return dp[n] = ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        for (int i = 1; i <= n; i++)
            dis[i] = INT_MAX;

        for (int i = 1; i <= n; i++)
            dp[i] = -1;
        vector<pair<int, int>> adlist[n + 1];

        for (auto i : edges)
        {
            adlist[i[0]].push_back({i[1], i[2]});
            adlist[i[1]].push_back({i[0], i[2]});
        }
        dijkatras(n, adlist);
        return dfs(n, adlist, 0);
    }
};

void solve()
{
    Solution a1;
    vector<vector<int>> a{{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2}, {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
    int ans = a1.countRestrictedPaths(5, a);
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