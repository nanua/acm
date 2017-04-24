#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, ans;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		while(q.size()) q.pop();
		for (int i = 1, t; i <= n; ++i) cin >> t, q.push(t);
		while(q.size() > 1) {
			ll x = q.top(); q.pop();
			ll y = q.top(); q.pop();
			q.push(x+y-1);
		}
		cin >> ans;
		puts(ans == q.top() ? "GREAT!" : "POOR!");
	}
}
 
