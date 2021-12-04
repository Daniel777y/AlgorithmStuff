/**
 * Author: Daniel
 * Created Time: 2021-01-02 20:02:35
**/

// time-limit: 2000
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

int n;
PII a[N];

bool check(int u, int v)
{
    int x1 = a[u].F, x2 = a[v].F;
    int y1 = a[u].S, y2 = a[v].S;
    double k = (double)(y1 - y2) / (double)(x1 - x2);
    return k <= 1.0 && k >= -1.0;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i].F >> a[i].S;

    int res = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = i + 1; j < n; j ++ )
            if (check(i, j))
                res ++ ;
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
