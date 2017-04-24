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

typedef double lint;
typedef long long ll;
typedef double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;



template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

bool cmp(const pii &x, const pii &y) {
	return x.fi *y.se > y.fi * x.se;
}
int n, m;
pii item[10001];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d",&m, &n), n != -1) {
		for (int i = 1; i <= n; ++i)
			cin >> item[i].fi >> item[i].se;

		sort(item+1, item+n+1, cmp);

		ld ans = 0;
		for (int i = 1; i <= n && m; ++i)
			if (item[i].se == 0) ans += item[i].fi;
			else 	ans += (ld)item[i].fi / item[i].se * min((double)m, item[i].se), m -= min((double)m, item[i].se);

		printf("%.3lf\n", ans);
	}
}
 
