#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 4e5+50, maxm = 4e5+50;
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

int n, m, a, b;
int d[4][maxn];
int u[maxm], v[maxm];

int edg;
int to[maxm], nt[maxm];
int la[maxn];

int hr, tl;
int q[maxn];

void add_edge(int x, int y) {
	to[++edg] = y, nt[edg] = la[x], la[x] = edg;
}

void bfs(int st, int dis[]) {
	hr = tl = 0;
	dis[q[++tl] = st] = 0;

	while (hr < tl) {
		int x = q[++hr];
		for (int i = la[x]; i; i = nt[i])
			if (dis[to[i]] > dis[x] + 1)
					dis[q[++tl] = to[i]] = dis[x] + 1;
	}
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for (int i = 1; i <= m; ++i) scanf("%d %d",&u[i], &v[i]);
	for (int i = 1; i <= m; ++i) add_edge(u[i], v[i]);

	memset(d, 0x3f, sizeof(d));

	bfs(0, d[1]);

	edg = 0;
	for (int i = 0; i <= n; ++i) la[i] = 0;
	for (int i = 1; i <= m; ++i) add_edge(v[i], u[i]);

	bfs(a, d[2]);
	bfs(b, d[3]);

	int ans = inf;

	for (int i = 0; i <= n; ++i)
		if (max(d[1][i], max(d[2][i], d[3][i])) != inf)
			ans = min(ans, d[1][i] + d[2][i] + d[3][i]);

	cout << ans;
}
