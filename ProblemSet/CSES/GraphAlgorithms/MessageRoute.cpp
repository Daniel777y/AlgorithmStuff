/**
 * Author: Daniel
 * Created Time: 2021-06-23 09:34:41
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
vector<A> Dijkstra(const vector<vector<pair<int, B> > > &g, int start, const A &INF, VI &pre) {
  int n = static_cast<int>(g.size());
  assert(start >= 0 && start < n);
  vector<A> dist(n, INF);
  dist[start] = 0;
  priority_queue<pair<A, int>, vector<pair<A, int> >, greater<pair<A, int> > > heap;
  heap.emplace(dist[start], start);
  while ((int) heap.size() > 0) {
    auto [d, u] = heap.top();
    heap.pop();
    if (dist[u] != d) {
      continue;
    }
    for (auto &[v, w] : g[u]) {
      if (dist[v] > w + dist[u]) {
        pre[v] = u;
        dist[v] = w + dist[u];
        heap.emplace(dist[v], v);
      }
    }
  }
  // returns INF if there's no path
  return dist;
}

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;



// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    VE<VPII> g(n);
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        g[a].EB(b, 1);
        g[b].EB(a, 1);
    }
    VI pre(n, -1);
    auto dist = Dijkstra(g, 0, INF, pre);
    if (dist.back() == INF)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    VI path;
    int cur = n - 1;
    while (true)
    {
        path.EB(cur);
        cur = pre[cur];
        if (cur == 0)
        {
            path.EB(0);
            break;
        }
    }
    reverse(ALL(path));
    cout << SZ(path) << '\n';
    for (auto &u : path) cout << u + 1 << ' ';
    cout << '\n';
    return 0;
}

// GOOD LUCK!!!
