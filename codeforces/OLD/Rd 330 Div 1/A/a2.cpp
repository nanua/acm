#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int ans = inf, n, p[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	sort(p + 1, p + n + 1);

	for (int i = 1; i + n/2 <= n; ++i)
		ans = min(ans, p[i+n/2] - p[i]);
	cout << ans;
}
