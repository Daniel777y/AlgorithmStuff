/**
*  Author: Daniel
*  Created Time: 2020-11-01 20:23:50
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define V(x) vector<x>
#define EB emplace_back
#define PII P(int, int)
#define lowbit(x) (x & -x)
#define P(x, y) pair<x, y>
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define HEAP(x) priority_queue<x>
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define RHEAP(x) priority_queue<x, vector<x>, greater<x> >
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) { return '"' + s + '"'; }
 
string to_string(const char* s) { return to_string((string) s); } 
string to_string(bool b) { return (b ? "true" : "false"); }
 
string to_string(vector<bool> v) 
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
 
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
 
void debug_out() { cout << '\n'; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }
 
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// check the limitation!!!
const int N = 300010, M = 1010, mod = 998244353;

int n;
int fact[N], infact[N];

LL qp(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qp(i, mod - 2) % mod;
    }
}

LL C(LL a, LL b)
{
    LL res;
    res = (LL)fact[a] * infact[a - b] % mod * infact[b] % mod;
    return res;
}

// read the question carefully!!!
int main()
{
    IOS

    init();

    cin >> n;

    V(int) a(n), b(n);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;
    sort(ALL(a));
    sort(RALL(b));

    int res = 0;
    for (int i = 0; i < n; i ++ )
        res = (res + abs(b[i] - a[i])) % mod;

    LL t = C(2 * n, n);
    res = res % mod * t % mod;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
