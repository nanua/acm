#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

ll f[2][(2<<21)+100];
int a[41];
int T, n, m, kase;

ll bfs() {
	int dfn = 0, Max = 0;
	f[0][0] = 1;

	for (int i = 1; i <= n; ++i, dfn ^= 1) {
		memset(f[dfn^1], 0, sizeof(f[dfn^1]));
		int Tmax = -1;
		for (int j = Max; j >= 0; --j)
			if (f[dfn][j])
				f[dfn^1][j] += f[dfn][j], f[dfn^1][j^a[i]] += f[dfn][j], Tmax = max(Tmax, max(j, j^a[i]));
		Max = Tmax;
	}

	ll ret = 0;
	for (int i = Max; i >= m; --i) ret += f[dfn][i];
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (gint(T); T--; ) {
		gint(n), gint(m);
		for (int i = 1; i <= n; ++i) gint(a[i]);

		cout << "Case #" << ++kase << ": " << bfs() << endl;
	}
	// cerr << (sizeof(f) / 1048576.0);
}
