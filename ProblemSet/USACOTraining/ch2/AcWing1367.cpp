/**
 * Author: Daniel
 * Created Time: 2020-12-10 21:28:58
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

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
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int n, c, x;
VE<int> on, off;
VE<int> ops;
VE<string> res;
int state[8][6] = 
{
    {0, 0, 0, 0, 0, 0},  // 0
    {1, 1, 1, 1, 1, 1},  // 1
    {1, 0, 1, 0, 1, 0},  // 2
    {0, 1, 0, 1, 0, 1},  // 3
    {1, 0, 0, 1, 0, 0},  // 4
    {0, 1, 1, 0, 1, 1},  // 14
    {0, 0, 1, 1, 1, 0},  // 24
    {1, 1, 0, 0, 0, 1},  // 34
};

bool check(string &s)
{
    for (auto &u : on)
        if (s[u % 6] == '0')
            return false;
    for (auto &u : off)
        if (s[u % 6] == '1')
            return false;
    return true;
}

void op(VE<int> ops)
{
    for (auto &op : ops)
    {
        string s(6, '1');
        for (int i = 0; i < 6; i ++ )
            if (state[op][i])
                s[i] = ((s[i] - '0') ^ 1) + '0';

        if (check(s)) res.EB(s);
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> c;
    while (cin >> x && x != -1) on.EB(x - 1);
    while (cin >> x && x != -1) off.EB(x - 1);

    if (c == 0) op({0});
    else if (c == 1) op({1, 2, 3, 4});
    else if (c == 2) op({0, 1, 2, 3, 5, 6, 7});
    else op({0, 1, 2, 3, 4, 5, 6, 7});

    if (SZ(res))
    {
        sort(ALL(res));
        for (auto &s : res)
        {
            for (int i = 0; i < n; i ++ )
                cout << s[i % 6];
            cout << '\n';
        }
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}

// GOOD LUCK!!!