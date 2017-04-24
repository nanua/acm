#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, ans;
set<int> s;
set<int>::iterator it;
pair<int, int> item[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		s.clear(), ans = 0;
		
		for (int i = 1; i <= n; ++i) cin >> item[i].fi >> item[i].se, item[i].fi *= -1;
		for (int i = 1; i <= 1e4; ++i) s.insert(-i);

		sort(item+1, item+n+1);
		
		for (int i = 1; i <= n; ++i)
			if ((it = s.lower_bound(-item[i].se)) != s.end())
				ans -= item[i].fi, s.erase(it);

		cout << ans << endl;		
	}
}
