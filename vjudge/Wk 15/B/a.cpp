#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m;
int a[maxn], b[maxn], f[maxn];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n) {
		for (int i = 1; i <= n; ++i)
			cin >> a[i] >> b[i];

		memset(f, 0, sizeof(f));

		cin >> m;
		for (int i = 1; i <= n; ++i)
			for (int j = b[i]; j <= m; ++j)
				f[j] = max(f[j], f[j-b[i]] + a[i]);

		cout << f[m] << endl;
	}
}
