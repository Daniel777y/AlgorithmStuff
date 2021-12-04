/**
 * Author: Daniel
 * Created Time: 2021-02-16 00:24:48
**/

// time-limit: 4000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

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

// check the limitation!!!
const int N = 150010, M = 1010, INF = 0x3f3f3f3f;

int n[4], m;
int a[4][N];
int f[4][N];

// read the question carefully!!!
int main()
{
    SOS;

    for (int i = 0; i < 4; i ++ ) cin >> n[i];
    for (int i = 0; i < 4; i ++ )
        for (int j = 1; j <= n[i]; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n[0]; i ++ ) f[0][i] = a[0][i];
    
    for (int k = 1; k < 4; k ++ )
    {
        cin >> m;
        VE<VI> g(n[k] + 1);
        for (int i = 0; i < m; i ++ )
        {
            int a, b;
            cin >> a >> b;
            g[b].EB(a);
        }

        multiset<int> S;
        for (int i = 1; i <= n[k - 1]; i ++ ) S.IS(f[k - 1][i]);
        for (int i = 1; i <= n[k]; i ++ )
        {
            for (auto &u : g[i]) S.ER(S.find(f[k - 1][u]));
            if (!SZ(S) || *S.begin() == INF) f[k][i] = INF;
            else f[k][i] = *S.begin() + a[k][i];
            for (auto &u : g[i]) S.IS(f[k - 1][u]);
        }
    }

    int mn = *min_element(f[3] + 1, f[3] + n[3] + 1);
    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}

// GOOD LUCK!!!
