#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e3 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, s, n, a[maxn], f[maxn][maxn][4][4];

inline void add(int &x, int y) {x += y; if (x > mod) x -= mod;}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T--; ) {
		cin >> n >> s;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		memset(f, 0, sizeof(f));
		f[0][0][0][0]  = 1; //obj, vol, all, ban;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= s; ++j)
				for (int k = 0; k <= 2; ++k)
					for (int l = 0; l <= 2; ++l) {
						int &p = f[i][j][k][l];
						if ((k <= 1) && (j+a[i+1]) <= s)
							add(f[i+1][j+a[i+1]][k+1][l], p);
						if (l <= 1)
							add(f[i+1][j][k][l+1], p);
						if (j + a[i+1] <= s)
							add(f[i+1][j+a[i+1]][k][l] ,p);
						add(f[i+1][j][k][l], p);
					}
		int ans = 0;
		for (int i = 0; i <= s; ++i) add(ans, f[n][i][2][2]);
		add(ans, ans), add(ans, ans);
		cout << ans << endl;
	}
}
 
