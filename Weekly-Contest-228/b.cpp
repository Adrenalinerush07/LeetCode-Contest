#include <bits/stdc++.h>
using namespace std;
// #define int long long

void __print(int x) { cerr << x; }
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
    long long int countHomogenous(string s)
    {
        long long int count = 1;
        long long int ans = 0, M = 1e9 + 7;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count = (count + 1) % M;
            }
            else
            {
                ans = (ans + ((count * (count + 1)) % M) / 2) % M;
                count = 1;
            }
        }
        if (count)
        {
            ans = (ans + ((count * (count + 1)) % M) / 2) % M;
        }
        return ans % M;
    }
};

void solve()
{
    Solution a1;
    // cout<<a1.countHomogenous("zzzzz");
    cout << a1.countHomogenous("abbcccaa");
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