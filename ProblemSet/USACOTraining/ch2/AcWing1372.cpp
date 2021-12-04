/**
 * Author: Daniel
 * Created Time: 2020-12-10 23:48:47
**/

#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
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
typedef pair<int, int> PII;
typedef unsigned long long ULL;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 110, M = 1010;

int n;
int w[N][N];
bool st[N][N];

void dfs(int a, int b)
{
    if (st[a][b]) return;
    st[a][b] = true;

    for (int i = 1; i <= 100; i ++ )
    {
        w[a][i] += w[b][i];
        if (st[i][a])
            dfs(i, b);
    }

    for (int i = 1; i <= 100; i ++ )
        if (w[a][i] > 50)
            dfs(a, i);
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n;
    for (int i = 1; i <= 100; i ++ ) st[i][i] = true;
    for (int i = 1; i <= n; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 1; j <= 100; j ++ )
            if (st[j][a])
            {
                w[j][b] += c;
                if (w[j][b] > 50) dfs(j, b);
            }
    }

    for (int i = 1; i <= 100; i ++ )
        for (int j = 1; j <= 100; j ++ )
            if (i != j && st[i][j])
                cout << i << ' ' << j << '\n';
    return 0;
}

// GOOD LUCK!!!