/**
 * Author: Daniel
 * Created Time: 2021-05-30 23:25:01
**/

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1523/problem/C
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
const int N = 100010, M = 1010;

void print(VI &a)
{
    int n = SZ(a);
    for (int i = 0; i < n; i ++ )
    {
        cout << a[i];
        cout << ".\n"[i == n - 1];
    }
}

// read the question carefully!!!
int main()
{
    SOS;

    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        VI a(n);
        for (auto &u : a) cin >> u;
        VI res{1};
        assert(a[0] == 1);
        print(res);
        for (int i = 1; i < n; i ++ )
        {
            int x = a[i];
            if (x == 1) res.EB(1);
            else if (res.back() - '0' + 1 == x) res.back() = x;
            else
            {
                while (SZ(res) && res.back() + 1 != x) res.PB();
                assert(SZ(res) > 0);
                res.back() = x;
            }
            print(res);
        }
    }
    return 0;
}

// GOOD LUCK!!!
