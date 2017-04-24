#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, n, vol;
ll f[1010], v[1010], w[1010];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	
	for (cin >> T; T; T--) {
		cin >> n >> vol;

		for (int i = 1; i <= n; ++i) cin >> v[i];
		for (int i = 1; i <= n; ++i) cin >> w[i];

		memset(f, 0, sizeof(f));

		for (int i = 1; i <= n; ++i)
			for (int j = vol; j >= w[i]; --j)
				f[j] = max(f[j], f[j-w[i]] + v[i]);
		cout << f[vol] << endl;
	}
}
 
