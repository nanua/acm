#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, b[maxn], c[maxn], d[maxn], s;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) cin >> c[i], s += b[i] + c[i];
 
	if (s % (2*n) != 0) goto fail;
	s /= 2*n;

	for (int i = 1; i <= n; ++i)
		if (b[i] + c[i] < s || (b[i] + c[i] - s) % n != 0) goto fail;
		else d[i] = (b[i]+c[i]-s) / n;
	
	for (int i = 1; i <= n; ++i) cout << d[i] << " ";
	return 0;
 fail:
	cout << -1;
}
