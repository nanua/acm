 #include <bits/stdc++.h>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;
typedef pair <lint, lint> pii;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}
int n, edg, tot;
arrn typ, to, nt, la, sz, bcnt;
void dfs1(int x, int f) {
	bcnt[x] = (typ[x] == 1), sz[x] = 1;
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f) {
			dfs1(to[i], x);
			bcnt[x] += bcnt[to[i]], sz[x] += sz[to[i]];
		}
}
void dfs2(int x, int f) {
	printf("%d ", x);
	if (tot == n) exit(0);
	for (int i = la[x]; i; i = nt[i])
		if (to[i] != f)
			while (bcnt[to[i]] < sz[to[i]]) {
				bcnt[x] -= bcnt[to[i]];
				typ[to[i]] *= -1, bcnt[to[i]] += typ[to[i]], tot += typ[to[i]];
				dfs2(to[i], x);
				bcnt[x] += bcnt[to[i]];
				typ[x] *= -1, bcnt[x] += typ[x], tot += typ[x];
				printf("%d ", x);
			}
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> typ[i];

	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, add_edge(u, v), add_edge(v, u);
	
	dfs1(1, 0);
	tot = bcnt[1];
	dfs2(1, 0);
	while (tot != n) {
		typ[to[la[1]]] *= -1, tot += typ[to[la[1]]], printf("%d ", to[la[1]]);
		if (tot == n) break;
		typ[1] *= -1, tot += typ[1], printf("%d ",1);
	}
}

