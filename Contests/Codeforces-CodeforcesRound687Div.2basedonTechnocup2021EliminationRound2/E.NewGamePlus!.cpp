/**
 * Author: Daniel
 * Created Time: 2020-12-04 13:11:50
**/

// time-limit: 2000
#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define lowbit(x) (x & -x)
#define SZ(x) (int)(x.size())
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define SOS; ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

typedef long long LL;
typedef pair<int, int> PII;

template <typename A> using VE = vector<A>;
template <typename A> using HEAP = priority_queue<A>;
template <typename A, typename B> using PA = pair<A, B>;
template <typename A> using RHEAP = priority_queue<A, vector<A>, greater<A> >;
    
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// check the limitation!!!
const int N = 100010, M = 1010;

int n, k;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> k;
    VE<int> a(n);
    for (auto &u : a) cin >> u;
    sort(RALL(a));

    HEAP<LL> heap;
    for (int i = 0; i < k + 1; i ++ ) heap.push(0);
    LL res = 0;
    for (auto &u : a)
    {
        res += heap.top();
        LL t = heap.top() + u;
        heap.pop();
        heap.push(t);
    }
    cout << res << '\n';
    return 0;
}

// GOOD LUCK!!!
