/**
 * Author: Daniel
 * Created Time: 2021-10-17 03:57:28
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

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); } 

string to_string(const char c) { return to_string((string)"" + c); } 

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
        res += ", ";
    } 
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A> heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(priority_queue<A, vector<A>, greater<A> > heap) {
    bool first = true;
    string res = "{";
    while ((int) heap.size()) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(heap.top());
        heap.pop();
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename ... Ts>
string to_string(const Ts& ... ts) {
    stringstream ss;
    const char* sep = "";
    ((static_cast<void>(ss << sep << ts), sep = ", "), ...);
    return ss.str();
}

template <typename... Args>
string to_string(const std::tuple<Args...> &t) {
    string res = "(";
    apply([&](const auto&... ts) { res += to_string(ts...); }, t);
    res += ")";
    return res;
}

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
const int N = 200010, M = 1010;

template <typename T, class F = function<T(const T&, const T&)>>
class Fenwick {
 public:
  int n;
  vector<T> val, fenw;
  F func;
 
  Fenwick (const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    val.resize(n);
    fenw.resize(n);
    for (int i = 1; i <= n; i++) {
      val[i - 1] = fenw[i - 1] = a[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
 
  // change value in k to v
  // k is [0, n)
  void modify(int k, T v) {
    val[k] = v;
    for (int i = k + 1; i <= n; i += lowbit(i)) {
      fenw[i - 1] = val[i - 1];
      int len = lowbit(i);
      for (int j = 1; j < len; j <<= 1) {
        fenw[i - 1] = func(fenw[i - 1], fenw[i - j - 1]);
      }
    }
  }
 
  // l and r are [0, n)
  // ask for [l, r]
  T query(int l, int r) {
    ++l, ++r;
    T res = val[r - 1];
    while (true) {
      res = func(res, val[r - 1]);
      if (l == r) break;
      for (--r; r - lowbit(r) >= l; r -= lowbit(r)) {
        res = func(res, fenw[r - 1]);
      }
    }
    return res;
  }
};

// read the question carefully!!!
int main()
{
    SOS;

    int n, q;
    cin >> n >> q;
    VL a(n);
    for (auto &u : a) cin >> u;
    VL b = a, c = a;
    for (int i = 0; i < n; i ++ )
    {
        b[i] -= i;
        c[i] += i;
    }
    Fenwick<LL> fen1(b, [&](LL i, LL j) { return min(i, j); });
    Fenwick<LL> fen2(c, [&](LL i, LL j) { return min(i, j); });
    while (q -- )
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k;
            LL x;
            cin >> k >> x;
            k -- ;
            fen1.modify(k, x - k);
            fen2.modify(k, x + k);
        }
        else
        {
            int k;
            cin >> k;
            k -- ;
            cout << min(fen1.query(0, k) + k, fen2.query(k, n - 1) - k) << '\n';
        }
    }
    return 0;
}

// GOOD LUCK!!!
