#include <bits/stdc++.h>
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


int dfs(int x, int t) {
	//1 lose, 2 win, 3 loop
	if (x == 1) return f[x][t] = 1;
	if (f[x][t] != 0) return f[x][t];

	for (int i = 1; i <= k[t]; ++i)
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;

	cin >> k[0];
	for (int i = 1; i <= k1; ++i) cin >> s[0][i];
	cin >> k[1];
	for (int i = 1; i <= k2; ++i) cin >> s[1][i];

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= 1; ++j)
			dfs(i, j);
}

