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
    int maximumScore(int a, int b, int c)
    {
        multiset<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);

        int cnt = 0;
        while (*s.begin() > 0 and s.size() > 1)
        {
            // cout<<"Elements of set are: ";
            // for(auto i:s){
            // 	cout<<i<<" ";
            // }
            // cout<<endl;
            cnt++;
            int t1 = *s.begin() - 1;
            int t2 = *prev(s.end()) - 1;
            s.erase(s.find(*s.begin()));
            s.erase(s.find(*prev(s.end())));
            if (t1 > 0)
            {
                s.insert(t1);
            }
            if (t2 > 0)
            {
                s.insert(t2);
            }
        }
        return cnt;
    }
};

void solve()
{
    Solution s1;
    // int ans=s1.maximumScore(2,4,6);
    int ans = s1.maximumScore(1, 8, 8);
    // int ans=s1.maximumScore(4,4,6);
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