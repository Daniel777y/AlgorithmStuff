/**
 * Author: Daniel
 * Created Time: 2021-05-25 22:58:25
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
const int N = 100010, M = 1010, INF = 0x3f3f3f3f;



// read the question carefully!!!
int main()
{
    SOS;

    int n, m;
    cin >> n >> m;
    VE<VI> g(n, VI(n, INF));
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < 2 * n; j ++ )
        {
            int a = j % n, b = (j + 1) % n;
            g[i][b] = min(g[i][b], g[i][a] + 1);
        }
    for (int start = 0; start < n; start ++ )
    {
        VI dist(n, INF);
        VB st(n, false);
        dist[start] = 0;
        while (true)
        {
            int t = -1;
            for (int j = 0; j < n; j ++ )
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                    t = j;
            if (t == -1) break;
            else st[t] = true;
            int r = dist[t] % n;
            for (int j = 0; j < n; j ++ )
            {
                dist[r] = min(dist[r], dist[t] + g[t][j]);
                r = (r + 1) % n;
            }
        }
        for (int i = 0; i < n; i ++ )
            cout << dist[i] << " \n"[i == n - 1];
    }
    return 0;
}

// GOOD LUCK!!!