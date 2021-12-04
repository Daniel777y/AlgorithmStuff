/**
 * Author: Daniel
 * Created Time: 2021-11-15 13:45:43
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1589/problem/D
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



// read the question carefully!!!
int main() {
  SOS;

  auto ask = [&](LL l, LL r) -> LL {
    assert(l <= r);
    cout << "? " << l << ' ' << r << endl;
    cin >> r;
    return r;
  };
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    LL tot = ask(1, n);
    LL l = 1, r = n;
    while (l < r) {
      LL mid = (l + r + 1) >> 1LL;
      if (ask(mid, n) >= tot) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    LL i = r;
    assert(i + 3 <= n);
    LL other = ask(i + 1, n);
    assert(tot > other);
    LL less = tot - other;
    LL j = i + less + 1;
    assert(j + 1 <= n);
    LL R = ask(j, n);
    LL ll = 1, rr = (LL) 1e9 + 10;
    while (ll < rr) {
      LL mid = (ll + rr) >> 1LL;
      if (mid * (mid - 1) / 2 >= R) {
        rr = mid;
      } else {
        ll = mid + 1;
      }
    }
    LL k = j + rr - 1;
    cout << "! " << i << ' ' << j << ' ' << k << endl;
  }
  return 0;
}

// GOOD LUCK!!!
