/**
 * Author: Daniel
 * Created Time: 2021-01-28 14:45:09
**/

// time-limit: 3000
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
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
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

// check the limitation!!!
const int N = 5010, M = 1010;
const LL mod = (LL)(1e9 + 7);

int n, m, k;
LL a[N];
LL f[N][N], cnt[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 1; i <= n; i ++ ) f[i][0] = 1;

    for (int j = 1; j <= k; j ++ )
        for (int i = 1; i <= n; i ++ )
        {
            if (i > 1) (f[i][j] += f[i - 1][j - 1]) %= mod;
            if (i < n) (f[i][j] += f[i + 1][j - 1]) %= mod;
        }

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= k; j ++ )
            (cnt[i] += f[i][j] * f[i][k - j] % mod) %= mod;

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) (res += cnt[i] * a[i] % mod) %= mod;

    while (m -- )
    {
        int x, c;
        cin >> x >> c;

        res -= cnt[x] * a[x];
        res = (res % mod + mod) % mod;
        a[x] = c;
        res += cnt[x] * a[x];
        res = (res % mod + mod) % mod;
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
