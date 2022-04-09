/**
 * Author: Daniel
 * Created Time: 2022-01-29 10:47:41
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1631/problem/C
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
#define SOS(x) ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(x)

typedef long long LL;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef long double LD;
typedef vector<char> VC;
typedef vector<bool> VB;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef tuple<int, int, int> TIII;
typedef vector<pair<LL, LL>> VPLL;
typedef vector<pair<int, int>> VPII;
typedef vector<tuple<int, int, int>> VTIII;

template <typename A> using VE = vector<A>;
template <typename A> using USET = unordered_set<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A, typename B> using UMAP = unordered_map<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A>>;

template <typename A> A MAX(const A &a) { return a; }
template <typename A> A MIN(const A &a) { return a; }
template <typename A> A MAX(const A *a, const A *b) { return *max_element(a, b); }
template <typename A> A MIN(const A *a, const A *b) { return *min_element(a, b); }
template <typename A> int CNT(const A *a, const A *b, const A &v) { return int(count(a, b, v)); }
template <typename A, typename... B> A MAX(const A &a, const B&... b) { return max(a, MAX(b...)); }
template <typename A, typename... B> A MIN(const A &a, const B&... b) { return min(a, MIN(b...)); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MAX(const A &a, const A &b) { return *max_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> B MIN(const A &a, const A &b) { return *min_element(a, b); }
template <typename A, typename B = typename std::iterator_traits<A>::value_type> int CNT(const A &a, const A &b, const B &v) { return int(count(a, b, v)); }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;



// read the question carefully!!!
int main() {
  SOS(10);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n <= 4 && n - 1 == k) {
      cout << "-1\n";
      continue;
    }
    int B = 0;
    int nn = n;
    while (nn > 1) {
      nn >>= 1;
      ++B;
    }
    auto Get = [&](int x) -> int {
      int res = 0;
      for (int bit = 0; bit < B; bit++) {
        if (((x >> bit) & 1) == 0) {
          res |= (1 << bit);
        }
      }
      return res;
    };
    VPII res;
    VB st(n);
    if (k == 0) {
      st[k] = st[n - 1] = true;
      res.EB(k, n - 1);
    } else if (k == n - 1) {
      st[k] = st[k - 1] = true;
      res.EB(k, k - 1);
      st[1] = st[k - 2] = true;
      res.EB(1, k - 2);
      st[0] = st[Get(k - 2)] = true;
      res.EB(0, Get(k - 2));
    } else {
      st[k] = st[n - 1] = true;
      res.EB(k, n - 1);
      st[0] = st[Get(k)] = true;
      res.EB(0, Get(k));
    }
    for (int i = 0; i < n; i++) {
      if (!st[i]) {
        int j = Get(i);
        assert(!st[j]);
        res.EB(i, j);
        st[i] = st[j] = true;
      }
    }
    assert(SZ(res) == n / 2);
    for (auto &[x, y] : res) {
      cout << x << ' ' << y << '\n';
    }
  }
  return 0;
}

// GOOD LUCK!!!