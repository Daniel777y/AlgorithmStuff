/**
 * Author: Daniel
 * Created Time: 2020-12-22 18:07:10
**/

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
const int N = 100010, M = 1010;

int T;
int n, m;
int p[N];

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> m;

        for (int i = 0; i <= n; i ++ ) p[i] = i;

        int res = 0;
        for (int i = 0; i < m; i ++ )
        {
            int x, y;
            cin >> x >> y;

            if (x == y) continue;

            int pa = find(x), pb = find(y);
            if (pa == pb) res += 2;
            else
            {
                res ++ ;
                p[pa] = pb;
            }
        }
        cout << res << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
