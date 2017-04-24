#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ll f[510][510], ans;
int n;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	f[0][0] = 1;
	for (int i = 1; i <= 500; ++i) //bricks
		for (int j = 1; j <= i; ++j) //last stair height
			for (int k = 0; k < j; ++k)
				f[i][j] += f[i-j][k];

	cin >> n;
	for (int i = 1; i <= n; ++i) ans += f[n][i];
	cout << ans-1;
}
