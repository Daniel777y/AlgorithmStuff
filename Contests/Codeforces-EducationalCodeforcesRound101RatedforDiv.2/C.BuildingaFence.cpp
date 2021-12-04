/**
 * Author: Daniel
 * Created Time: 2020-12-30 16:10:35
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
const int N = 200010, M = 1010;

int T;
int n, k;
int h[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++ ) cin >> h[i];

        int l = h[1], r = h[1];
        bool flag = true;
        for (int i = 2; i <= n; i ++ )
        {
            if (i != n)
            {
                l = max(h[i], l - k + 1);
                r = min(h[i] + k - 1, r + k - 1);
            }
            else
            {
                l = max(h[i], l - k + 1);
                r = min(h[i], r + k - 1);
            }
            if (l > r) flag = false;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

// GOOD LUCK!!!
