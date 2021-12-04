/**
*  Author: Daniel
*  Created Time: 2020-11-02 20:41:48
**/

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
const int N = 100010, M = 1010;

int n;
string s;

// read the question carefully!!!
int main()
{
    IOS

    cin >> s;
    n = SZ(s);

    bool flag = false;
    if (n <= 3)
    {
        V(int) a;
        for (auto &u : s) a.EB(u - '0');
        sort(ALL(a));

        do
        {
            int t = 0;
            for (auto &u : a) t = t * 10 + u;
            if (t % 8 == 0) flag = true;
        } while (next_permutation(ALL(a)));
    }
    else
    {
        V(int) cnt(10);
        for (auto &u : s) cnt[u - '0'] ++ ;
        for (int i = 1; i <= 9; i ++ )
            for (int j = 1; j <= 9; j ++ )
                for (int k = 1; k <= 9; k ++ )
                {
                    int t = i * 100 + j * 10 + k;
                    if (t % 8) continue;

                    V(int) tcnt(10);
                    tcnt[i] ++ ;
                    tcnt[j] ++ ;
                    tcnt[k] ++ ;

                    bool ok = true;
                    for (int l = 0; l <= 9; l ++ )
                        if (cnt[l] < tcnt[l])
                            ok = false;
                    if (ok) flag = true;
                }
    }

    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

// GOOD LUCK!!!
