/**
* Author: Name
* Created Time: 2020-11-21 20:14:04
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
const int N = 200010, M = 1010;

int n, tt;
char stk[N];
string s;

bool check()
{
    if (tt < 3) return false;
    if (stk[tt] == 'x' && stk[tt - 1] == 'o' && stk[tt - 2] == 'f') return true;
    else return false;
}

// read the question carefully!!!
int main()
{
    SOS;

    cin >> n >> s;

    int cnt = 0;
    for (auto &u : s)
    {
        stk[ ++ tt] = u;
        if (check())
        {
            tt -= 3;
            cnt ++ ;
        }
    }

    cout << n - cnt * 3 << '\n';
    return 0;
}

// GOOD LUCK!!!