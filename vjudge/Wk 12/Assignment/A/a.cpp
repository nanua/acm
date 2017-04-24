#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n, c, x[maxn];

int check(int maxd) {
	int las = -inf, i, j;
	for (i = 1, j = 1; i <= c; ++i) {
		for (; j <= n && x[j] - las < maxd; ++j);
		if (j <= n && x[j] - las >= maxd) las = x[j];
		else return 0;
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d %d\n", &n, &c);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);

	sort(x+1, x+n+1);
	
	int l = 0, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) >> 1;
		check(mid) ? l = (ans = mid) + 1 : r = mid-1;
	}

	cout << ans;
}
 
