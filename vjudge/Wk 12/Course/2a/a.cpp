#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int T, n, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a+1,a+n+1);

		int ans = 0;
		ans += (unique(a+1, a+n+1)-a-1)*5;
		ans += n;
		ans += a[n]*10;

		cout << ans << endl;		
	}
}
