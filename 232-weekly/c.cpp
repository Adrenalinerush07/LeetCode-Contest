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

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        double t1 = (double)(a.first + 1) / (double)(a.second + 1) - (double)a.first / (double)a.second;
        double t2 = (double)(b.first + 1) / (double)(b.second + 1) - (double)b.first / (double)b.second;
        return t1 < t2;
    }
};
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

        for (auto i : classes)
        {
            q.push({i[0], i[1]});
        }

        while (extraStudents--)
        {
            auto cur = q.top();
            q.pop();

            cur.first++;
            cur.second++;

            q.push(cur);
        }

        double ans = 0.0;
        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();
            ans += (double)cur.first / (double)cur.second;
        }
        return (double)ans / (double)classes.size();
    }
};

void solve()
{
    vector<vector<int>> a{{1, 2}, {3, 5}, {2, 2}};
    Solution a1;

    cout << a1.maxAverageRatio(a, 2);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}