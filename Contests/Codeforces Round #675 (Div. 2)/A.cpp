
// Problem: A. Fence
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define F first 
#define S second
#define IS insert
#define PI acos(-1)
#define PB pop_back
#define EB emplace_back
#define SZ(x) (int)x.size()
#define MP(x, y) make_pair(x, y)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<fixed<<setprecision(10);

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

// check the limitation!!!
const int N = 3, M = 1010;

int T;
int a[N];

// read the question carefully!!!
int main()
{
	cin >> T;
	while (T -- )
	{
		for (int i = 0; i < N; i ++ ) cin >> a[i];
		sort(a, a + N);
		cout << a[2] << '\n';
	}
    return 0;
}