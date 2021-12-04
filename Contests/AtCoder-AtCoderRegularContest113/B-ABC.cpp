/**
 * Author: Daniel
 * Created Time: 2021-02-21 20:05:46
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
#define SOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10)

typedef long long LL;
typedef vector<LL> VL;
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

int a, b, c;

int qp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (LL)res * a % 10000;
        a = (LL)a * a % 10000;
        b >>= 1;
    }
    return res;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> a >> b >> c;
    int t = qp(b, c);
    cout << qp(a, (t ? t : 10000)) % 10 << '\n';
    return 0;
}

// GOOD LUCK!!!
