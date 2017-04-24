#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
ll n, f[maxn][2];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	f[1][0] = 1;
	f[1][1] = 2;
	for (int i = 2; i < 40; ++i) {
		f[i][1] = (f[i-1][1] + f[i-1][0]) << 1;
		f[i][0] = f[i-1][1];
	}
	while (cin >> n)
		cout << f[n][0] + f[n][1] << endl;
}
