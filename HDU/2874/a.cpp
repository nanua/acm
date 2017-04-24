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

#define For(x, l, r) for (register lint x = (l), end = (r); x <= end; ++x)
#define Rof(x, l, r) for (lint x = (l), end = (r); x >= end; --x)
#define For_edge(x, y) for (lint x = la[y]; x; x = nt[x])
#define Add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define Add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define Lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef pair <lint, pii> tpi;
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

arrn _rmq[21], maxd, mind, fa, d[2], lg, nt, wgt, la, to;
lint n, m, c, cnt, edg, sz;
tpi edges[maxn];

inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline int tmin(const int x, const int y) {
	return d[0][x] < d[0][y] ? x : y;
}
void rmq_init() {
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j+(1<<i)-1 <= sz; ++j)
			_rmq[i][j] = tmin(_rmq[i-1][j], _rmq[i-1][j+(1<<(i-1))]);
}

int rmq(int l, int r) {
	int k = lg[r-l+1];
	return tmin(_rmq[k][l], _rmq[k][r-(1<<k)+1]);
}

void dfs(int x, int f, int _wgt) {
	_rmq[0][maxd[x] = mind[x] = ++sz] = x;
	d[0][x] = d[0][f] + 1;
	d[1][x] = d[1][f] + _wgt;
		
	For_edge(i, x)
		if (to[i] != f)	
			dfs(to[i], x, wgt[i]), _rmq[0][maxd[x] = ++sz] = x;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	For (i, 2, 1e5) lg[i] = lg[i/2]+1;

	while (~scanf("%d %d %d", &n, &m, &c)) {		
		For (i, 1, n) la[i] = 0, mind[i] = inf, maxd[i] = -inf;
		edg = sz = 0;
		
		int u, v, w;
		For (i, 1, m) {
			gint(u), gint(v), gint(w);
			edges[i] = tpi(w, pii(u, v));
		}

		sort(edges+1, edges+m+1);

		For (i, 1, n) fa[i] = i;

		For (i, 1, m)
			if (find(edges[i].se.fi) != find(edges[i].se.se)) {
				fa[find(edges[i].se.fi)] = fa[find(edges[i].se.se)];
				Add_wedge(edges[i].se.fi, edges[i].se.se, edges[i].fi);
				Add_wedge(edges[i].se.se, edges[i].se.fi, edges[i].fi);
			}

		For (i, 1, n)
			if (mind[i] == inf) dfs(i, 0, 0);

		rmq_init();

		For (i, 1, c) {
		      gint(u), gint(v);
			if (find(u) != find(v)) puts("Not connected");
			else printf("%d\n", d[1][u] + d[1][v] -
					2*d[1][rmq(min(mind[u], mind[v]), max(maxd[u], maxd[v]))]);
		}
	}
} 
