#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, a[1010][1010];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j) cin >> a[i][j];
	for (int i = n-1; i >= 1; --i)
		for (int j = 1; j <= i; ++j)
			a[i][j] += max(a[i+1][j], a[i+1][j+1]);

	cout << a[1][1];
}
