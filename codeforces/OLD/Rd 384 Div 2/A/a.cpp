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

vint v[2];
vint::iterator itr[2];

template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int n, a, b, ans, t[maxn];
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> a >> b;

	for (int i = 1; i <= n; ++i)
		scanf("%1d",&t[i]), v[t[i]].pb(i);

	v[1].pb(-inf), v[1].pb(inf);
	sort(all(v[0])), sort(all(v[1]));

	ans = (t[a] != t[b]) * inf;

	for (itr[0] = v[0].begin(); itr[0] != v[0].end(); ++itr[0]) {
		itr[1] = lower_bound(all(v[1]), *itr[0]);
		ans = min(ans, abs(*itr[0]-*itr[1]));
		ans = min(ans, abs(*itr[0]-*(--itr[1])));
	}
	cout << ans;
}

