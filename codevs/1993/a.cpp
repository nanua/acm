#include <bits/stdc++.h>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((LL)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

arrm to, cap, nxt, las, d, q;
int n, m, src, snk, maxflow, edg = 1;

void add_wedge(int x, int y, int w) {
	to[++edg] = y, cap[edg] = w, nxt[edg] = las[x], las[x] = edg;
	to[++edg] = x, cap[edg] = 0, nxt[edg] = las[y], las[y] = edg;
}

bool bfs() {
	for (int i = 1; i <= m; ++i) d[i] = -1;
	
	int h = 0, t = 0;
	d[q[++t] = src] = 0;
	while (++h <= t) {
		for (int x = q[h], i = las[x]; i; i = nxt[i])
			if (cap[i] && d[to[i]] == -1)
				d[q[++t] = to[i]] = d[x] + 1;
	}

	return d[snk] != -1;
}

int dfs(int x, int a, int f = 0) {
	if (x == snk) return a;

	for (int t, i = las[x]; a && i; i = nxt[i])
		if (d[to[i]] == d[x] + 1 && (t = dfs(to[i], min(a, cap[i]))) > 0)
			cap[i] -= t, cap[i^1] += t, f += t, a -= t;

	return f;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m, src = 1, snk = m;
	
	for (int u, v, w, i = 1; i <= n; ++i)
		cin >> u >> v >> w, add_wedge(u, v, w);

	while (bfs())
		maxflow += dfs(src, inf);

	cout << maxflow;
}
