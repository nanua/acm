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
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
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

arrn la, nt, col, vis, to, mt;
int n, m, u, v, edg, ans;

bool dfs(int x, int c) {
	if (col[x] != -1) return col[x] == c;

	col[x] = c;	
	for (int i = la[x]; i; i = nt[i])
		if (!dfs(to[i], c^1)) return 0;
	return 1;
}

int find(int x) {
	for (int i = la[x]; i; i = nt[i])
		if (!vis[to[i]]) {
			vis[to[i]] = 1;
			if (!mt[to[i]] || find(mt[to[i]]))
				return mt[to[i]] = x, 1;
		}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d",&n, &m)) {
		ans = edg = 0;
		for (int i = 1; i <= n; ++i) col[i] = -1, la[i] = mt[i] = 0;
		
		for (int i = 1; i <= m; ++i) {
			gint(u), gint(v);
			add_edge(u, v), add_edge(v, u);
		}
		
		for (int i = 1; i <= n; ++i)
			if (col[i] == -1)
				if (!dfs(i, 0)) goto fail;

		for (int i = 1; i <= n; ++i)
			if (col[i] == 0) {
				fill(vis+1, vis+n+1, 0);
				ans += find(i);
			}

		printf("%d\n", ans);
		continue;
		
	fail:
		puts("No");
	}
}
