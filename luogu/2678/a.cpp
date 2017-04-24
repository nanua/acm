#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int le, n, m, d[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> le >> n >> m;

	for (int i = 1; i <= n; ++i) cin >> d[i];

	int l = 0, r = le, mid, ans; 
	while (l <= r) {
		mid = (l + r) >> 1;
		for (int i = 1, j, cnt = 0; i <= n; i = j-1) {
			for (j = i+1; j <= n && d[j] - d[i] <= mid; ++j) ++cnt;
			cnt -= 2;
			if (j-1 == i || cnt > m) goto gt;
		}
		l = mid+1, ans = mid;
		continue;
	gt:;
		r = mid-1;
	}
	cout << ans;
}
