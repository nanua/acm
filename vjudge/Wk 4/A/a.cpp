#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
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
const int maxm = 1e4+1, maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, lc[maxm], a[maxn], l[maxn], r[maxn];
ll ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (scanf("%d", &n) == 1) {
		ans = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), l[i] = 0, r[i] = n+1;
		
		memset(lc, 0, sizeof(lc));
		for (int i = 1; i <= n; i++) {
			for (int j = 1, q = sqrt(a[i]); j <= q; ++j)
				if (a[i] % j == 0) l[i] = max(l[i], max(lc[a[i]/j], lc[j]));
			lc[a[i]] = i;
		}
		
		memset(lc, 0x3f, sizeof(lc));		
		for (int i = n; i >= 1; i--) {
			for (int j = 1, q = sqrt(a[i]); j <= q; ++j)
				if (a[i] % j == 0) r[i] = min(r[i], min(lc[a[i]/j], lc[j]));
			lc[a[i]] = i;
		}

		for (int i = 1; i <= n; ++i)
			ans = (ans + (i-l[i])*(r[i]-i)) % mod;
		cout << ans << endl;
	}
}

