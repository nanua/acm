#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int T, n, m;
int p[maxn], h[maxn], c[maxn], f[200][200];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T--;) {
		cin >> n >> m;
		for (int i = 1; i <= m; ++i)
			cin >> p[i] >> h[i] >> c[i];

		memset(f, 0, sizeof(f));

		for (int i = 1; i <= m; ++i)
			for (int j = 0; j <= c[i]; ++j)
				for (int k = 0; k <= n; ++k)
					f[i][k] = max(f[i][k], max(f[i-1][k], k<j*p[i] ? -1 : f[i-1][k-j*p[i]] + h[i]*j));

		cout << f[m][n] << endl;
	}
}
