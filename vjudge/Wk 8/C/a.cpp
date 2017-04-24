#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, n, m, k, psz, a[maxn], pos[maxn];
ll ans;
inline int getint(char ch = getchar(), int ret = 0) {
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) ret = ret * 10 + ch - 48, ch = getchar();
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (T = getint(); T; T--, psz = ans = 0) {
		n = getint(), m = getint(), k = getint();
		for (int i = 1; i <= n; ++i) {
			a[i] = getint();
			if (a[i] >= m) pos[++psz] = i;
		}
		for (int i = 1, st = 0; i <= psz; st = pos[i++])
			if (i + k - 1 <= psz)
				ans += ll(pos[i] - st) * ll(n-pos[i+k-1]+1);

		cout << ans << endl;
	}
}
 
