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

vector<int> dijkstra(int n, unordered_map<int, vector<pair<int, int>>> edge, int src)
{
    vector<int> dist(n + 1, INT_MAX);
    set<pair<int, int>> heap;
    vector<bool> visited(n + 1, false);
    dist[src] = 0;
    heap.insert({dist[src], src});
    while (!heap.empty())
    {
        pair<int, int> curr = *heap.begin();
        heap.erase(heap.begin());
        if (visited[curr.second])
            continue;
        visited[curr.second] = true;
        for (auto it : edge[curr.second])
        {
            if (visited[it.first])
                continue;
            if (dist[it.first] > dist[curr.second] + it.second)
            {
                dist[it.first] = dist[curr.second] + it.second;
                heap.insert({dist[it.first], it.first});
            }
        }
    }
    return dist;
}

int dfs(vector<int> dis, unordered_map<int, vector<pair<int, int>>> edge, vector<int> &dp, int node)
{
    int mod = 1e9 + 7;
    if (node == 1)
    {
        return 1;
    }
    if (dp[node] != -1)
    {
        return dp[node];
    }
    int weight, val;
    int sum = 0;
    weight = dis[node];
    for (auto i : edge[node])
    {
        val = dis[i.first];
        if (val > weight)
        {
            sum = ((sum % mod + dfs(dis, edge, dp, i.first) % mod) % mod);
        }
    }
    return dp[node] = sum % mod;
}

int countRestrictedPaths(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> edge;
    for (auto i : edges)
    {
        pair<int, int> hm = {i[1], i[2]};
        edge[i[0]].push_back(hm);
        pair<int, int> hm2 = {i[0], i[2]};
        edge[i[1]].push_back(hm2);
    }

    vector<int> dis = dijkstra(n, edge, n);

    vector<int> dp(n + 1, -1);
    return dfs(dis, edge, dp, n);
}

void solve()
{
    vector<vector<int>> a{{1, 2, 3}, {1, 3, 3}, {2, 3, 1}, {1, 4, 2}, {5, 2, 2}, {3, 5, 1}, {5, 4, 10}};
    int ans = countRestrictedPaths(5, a);
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