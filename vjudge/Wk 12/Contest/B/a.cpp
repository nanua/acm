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
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int T, n, t;
ll d[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n",&T); T; T--) {
		scanf("%d\n",&n);
		for (int i = 1; i < n; ++i) scanf("%d",&t), d[i] = d[i-1] + t;

		ll l = 0, r = 1e18, mid, ans;
		while (l <= r) {
			mid = (l+r) >> 1;
			int i, j;
			for (i = 1; i < n && d[i] <= mid; ++i);
			for (j = i; j < n && d[j]-d[i] <= mid; ++j);
			if (d[n-1]-d[j-1] <= mid)
				ans = mid, r = mid-1;
			else
				l = mid+1;
		}
		cout << ans << endl;
	}
}
