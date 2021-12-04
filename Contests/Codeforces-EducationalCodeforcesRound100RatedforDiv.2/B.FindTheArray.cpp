/**
 * Author: Daniel
 * Created Time: 2020-12-17 22:44:01
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

int T;
int n, a[N], b[N];

// read the question carefully!!!
int main()
{
    SOS;

    cin >> T;
    while (T -- )
    {
        cin >> n;
        LL sum = 0;
        for (int i = 1; i <= n; i ++ ) 
        {
            cin >> a[i];
            b[i] = a[i];
            sum += a[i];
        }

        LL tot1 = 0, tot2 = 0;
        for (int i = 1; i <= n; i ++ )
            if (i & 1) tot1 += abs(1 - a[i]);
            else tot2 += abs(1 - a[i]);

        if (2LL * tot1 <= sum)
        {
            for (int i = 1; i <= n; i ++ )
                if (i & 1) cout << "1 ";
                else cout << a[i] << ' ';
        }
        else
        {
            for (int i = 1; i <= n; i ++ )
                if (i & 1) cout << a[i] << ' ';
                else cout << "1 ";
        }
        cout << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
