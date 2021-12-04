/**
 * Author: Daniel
 * Created Time: 2021-08-10 16:36:18
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;

const PII freeMove[] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
const PII costMove[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-2, -1}, {-2, 0}, {-2, 1}, {2, -1}, {2, 0}, {2, 1}, {-1, -2}, {0, -2}, {1, -2}, {-1, 2}, {0, 2}, {1, 2}};

// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    VS g(n);
    for (auto &s : g) cin >> s;
    deque<PII> q;
    VI dist(n * m, INF);
    q.EB(0, 0);
    while (SZ(q) > 0)
    {
        auto [u, d] = q.front();
        q.pop_front();
        if (dist[u] != INF) continue;
        else dist[u] = d;
        for (auto [dx, dy] : freeMove)
        {
            int tx = u / m + dx;
            int ty = u % m + dy;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
            if (g[tx][ty] != '.') continue;
            q.emplace_front(tx * m + ty, dist[u]);
        }
        for (auto &[dx, dy] : costMove)
        {
            int tx = u / m + dx;
            int ty = u % m + dy;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
            q.emplace_back(tx * m + ty, dist[u] + 1);
        }
    }
    cout << dist[n * m - 1] << '\n';
    return 0;
}

// GOOD LUCK!!!
