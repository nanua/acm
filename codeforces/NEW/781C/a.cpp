#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 4e5+50, maxm = 1e5+50;
const int inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ll arrm[maxn];

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m, k, edg, sz;
arrn to, nt, la, q, vis;

void dfs(int x) {
	vis[q[++sz] = x] = 1;
	for (int i = la[x]; i; i = nt[i])
		if (!vis[to[i]])
			dfs(to[i]), q[++sz] = x;
}
void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
	to[++edg] = x, nt[edg] = la[y], la[y] = edg;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m >> k;
	for (int i = 1, u, v; i <= m; ++i)
		cin >> u >> v, add_edge(u, v);

	dfs(1);

	int l = int(ceil(2.0*n/k)), cnt = 0;
	for (int i = 1; i <= sz; ) {
		int t = min(l, sz-i+1);
		cout << t << " ";
		for (int j = 1; j <= t; ++j, ++i)
			cout << q[i] << " ";
		cout << endl;
		++cnt;
	}
	for (int i = cnt; i < k; ++i)
		puts("1 1");
}

