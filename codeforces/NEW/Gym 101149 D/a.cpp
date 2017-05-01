#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 5e5+50;
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

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int edg = 1;
int cap[maxm], to[maxm], nt[maxm];
int la[maxn], d[maxn];

int n, m, r, c, nsz;
int src, snk;
int val[55][55], in[55][55], out[55][55], id[55][55];

char ch[55][55];

void add_edge(int x, int y, int w) {
	cap[++edg] = w, to[edg] = y, nt[edg] = la[x], la[x] = edg;
	cap[++edg] = 0, to[edg] = x, nt[edg] = la[y], la[y] = edg;
}

int bfs() {
	int hr = 0, tl = 0;
	static int q[maxn];

	for (int i = 1; i <= nsz; ++i) d[i] = inf;
	d[q[++tl] = src] = 1;

	while (hr < tl) {
		int x = q[++hr];
		for (int i = la[x]; i; i = nt[i])
			if (cap[i] && d[to[i]] == inf)
				d[q[++tl] = to[i]] = d[x] + 1;
	}

	return d[snk] != inf;
}

int dfs(int x, int a) {
	if (!a || x == snk) return a;
	int f = 0;
	for (int t, i = la[x]; i && a; i = nt[i])
		if (d[to[i]] == d[x] + 1 && (t = dfs(to[i], min(cap[i], a))) > 0)
			cap[i] -= t, cap[i^1] += t, a -= t, f += t;

	return f;
}

int max_flow() {
	int flow = 0;
	while (bfs())
		flow += dfs(src, inf);
	return flow;
}

void bfs2() {
	static pii q[maxn];
	static bool vis[55][55];
	memset(vis, 0, sizeof(vis));
	int hr = 0, tl = 0;
	q[++tl] = pii(r, c);
	vis[r][c] = 1;
	while (hr < tl) {
		pii x = q[++hr];
		for (int k = 0; k < 4; ++k) {
			pii y = pii(x.fi+dx[k], x.se+dy[k]);
			if (1 <= y.fi && y.fi <= n && 1 <= y.se && y.se <= m && !vis[y.fi][y.se]) {
				vis[y.fi][y.se] = 1;
				if (cap[id[y.fi][y.se]] > 0)
					q[++tl] = y;
				else
					ch[y.fi][y.se] = 'X';
			}

		}
	}
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> m >> r >> c;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cin >> val[i][j];

	src = ++nsz;
	snk = ++nsz;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			in[i][j] = ++nsz, out[i][j] = ++nsz;
			add_edge(in[i][j], out[i][j], val[i][j]);
			id[i][j] = edg - 1;
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k < 4; ++k)
				if (1 <= i + dx[k] && i + dx[k] <= n && 1 <= j + dy[k] && j + dy[k] <= m) {
					add_edge(out[i][j], in[i+dx[k]][j+dy[k]], inf);
					add_edge(out[i+dx[k]][j+dy[k]], in[i][j], inf);
				}

	for (int i = 1; i <= n; ++i)
		add_edge(out[i][1], snk, inf), add_edge(out[i][m], snk, inf);
	for (int i = 1; i <= m; ++i)
		add_edge(out[1][i], snk, inf), add_edge(out[n][i], snk, inf);

	add_edge(in[r][c], out[r][c], inf);
	add_edge(src, in[r][c], inf);

	cout << max_flow() << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) ch[i][j] = '.';

	bfs2();

	for (int i = 1; i <= n; puts(ch[i++]+1));
}
