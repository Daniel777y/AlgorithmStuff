/**
 * Author: Daniel
 * Created Time: 2021-02-05 00:11:10
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

string s;

// read the question carefully!!!
int main()
{
    SOS;

    cin >> s;
    int b = s.back() - '0';
    int i = 0;
    int a = 0, c = 1;
    while (s[i] != '-')
    {
        a += (s[i] - '0') * c;
        i ++ , c ++ ;
    }
    i ++ ;
    while (s[i] != '-')
    {
        a += (s[i] - '0') * c;
        i ++ , c ++ ;
    }
    i ++ ;
    while (s[i] != '-')
    {
        a += (s[i] - '0') * c;
        i ++ , c ++ ;
    }
    a %= 11;
    if (a == 10 && s.back() == 'X' || a == b) cout << "Right\n";
    else
    {
        for (int i = 0; i < SZ(s) - 1; i ++ ) cout << s[i];
        if (a == 10) cout << "X\n";
        else cout << a << '\n';
    }
    return 0;
}

// GOOD LUCK!!!
