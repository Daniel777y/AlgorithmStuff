/**
 * Author: Daniel
 * Created Time: 2021-05-31 11:25:17
**/

// time-limit: 3000
// problem-url: https://codeforces.com/contest/1523/problem/E
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define ER erase
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define MP make_pair
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL> > VPLL;
typedef vector<pair<int, int> > VPII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(A a, A b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(A a, A b) { return *min_element(a, b); }

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010, mod = 1e9 + 7;

int fact[N], infact[N];

void init(int n)
{
    fact[0] = fact[1] = 1;
    infact[0] = infact[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)(mod - mod / i) * infact[mod % i] % mod;
    }
    for (int i = 2; i <= n; i ++ ) infact[i] = (LL)infact[i] * infact[i - 1] % mod;
}

int C(int a, int b)
{
    if (a < b) return 0;
    else return (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int qp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    init(N - 1);
    int T;
    cin >> T;
    while (T -- )
    {
        int n, k;
        cin >> n >> k;
        int res = 1;
        for (int i = 1; i <= n - (k - 1) * (i - 1); i ++ )
            res = (res + (LL)C(n - (k - 1) * (i - 1), i) * qp(C(n, i), mod - 2) % mod) % mod;
        res = (res % mod + mod) % mod;
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
