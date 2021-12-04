/**
 * Author: Daniel
 * Created Time: 2021-10-14 17:42:43
**/

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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

template <typename T>
class Fenwick {
 public:
  vector<T> fenw;
  int n;
  Fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  inline void add(int x, T v) {
    assert(x >= 0 && x < n);
    while (x < n) {
      fenw[x] ^= v;
      x |= (x + 1);
    }
  }
  inline T get(int x) {
    T res{};
    while (x >= 0) {
      res ^= fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  inline T get(int l, int r) {
    assert(l >= 0 && l < n && r >= 0 && r < n);
    T res = get(r);
    if (l - 1 >= 0) {
      res ^= get(l - 1);
    }
    return res;
  }
};
// struct node {
//   int a = ...; // don't forget to set default value
//   inline void operator += (node &other) {
//     ...
//   }
// };

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    Fenwick<int> fen(n);
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        fen.add(i, x);
    }
    while (m -- )
    {
        int l, r;
        cin >> l >> r;
        l -- , r -- ;
        cout << fen.get(l, r) << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
