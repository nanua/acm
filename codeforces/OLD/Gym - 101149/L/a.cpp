#include <bits/stdc++.h>
using namespace std;

#define R "%d"
#define RL "%I64d"
#define RD "%lf"
#define W "%.8lf"

#define Clr(x, y) memset(x, y, sizeof(x))
#define Cpy(x, y) memcpy(x, y, sizeof(y))
#define All(x) x.begin(), x.end()
#define Sqr(x) ((x) * (x))
#define Sz(x) ((LL)x.size())

#define Mk make_pair
#define Pb push_back
#define Pk pop_back
#define Fr first
#define Se second

#define For(x, l, r) for (ll x = (l), end = (r); x <= end; ++x)
#define Rof(x, l, r) for (ll x = (l), end = (r); x >= end; --x)
#define Edge(x, y) for (ll x = la[y]; x; x = nt[x])
#define Add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define Add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define Lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef pair <lint, lint> PI;
typedef map <lint, lint> MI;
typedef set <lint> SI;
typedef queue <lint> QI;
typedef vector <lint> VI;

const ld eps = 1e-12, pi = M_PI;
const lint maxn = 2e5+50, maxm = 4e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];

lint gint(lint ret = 0, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret;
}

lint m, n, a, b, edg, ans = inf;
arrm to, nt, la, qu, u, v;
arrm dis[3];

void spfa(lint s, lint d[]) {
	For (i, 0, n) d[i] = inf;
	d[s] = 0;
	int fr = 0, tl = 0;
	qu[++tl] = s;
	while (++fr <= tl) {
		lint x = qu[fr];
		Edge(i, x)
			if (d[to[i]] == inf)
				d[qu[++tl] = to[i]] = d[x] + 1;
	}
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	n = gint(), m = gint(), a = gint(), b = gint();

	For (i, 1, m)
		u[i] = gint(), v[i] = gint(), Add_edge(u[i], v[i]);

	spfa(0, dis[0]);

	Clr(la, 0), edg = 0;
	For (i, 1, m) Add_edge(v[i], u[i]);
	
	spfa(a, dis[1]);
	spfa(b, dis[2]);

	For (i, 0, n)
		ans = min(ans, dis[0][i] + dis[1][i] + dis[2][i]);

	cout << ans;
}

