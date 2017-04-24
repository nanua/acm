#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> tpi;

const int maxn = 5e5+50, maxm = 5e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m, p, ans;
arrn ufs, sz, res;
pii qer[maxn];
tpi e[maxm];

int find(int x) {
	return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= m; ++i)
			gint(e[i].se.fi), gint(e[i].se.se), gint(e[i].fi);

		gint(p);
		for (int i = 1; i <= p; ++i)
			gint(qer[i].fi), qer[i].se = i;

		for (int i = 1; i <= n; ++i) 
			ufs[i] = i, sz[i] = 1;
		ans = 0;

		sort(e+1, e+m+1);
		sort(qer+1, qer+p+1);

		for (int c = 1, i = 1; c <= p; ++c) {
			for (; i <= m && e[i].fi < qer[c].fi; ++i) {
					int u = find(e[i].se.fi+1);
					int v = find(e[i].se.se+1);
					if (u != v) {
						ans += sz[u] * sz[v] * 2;
						ufs[v] = ufs[u], sz[u] += sz[v];	 
					}
				}
			res[qer[c].se] = n*(n-1) - ans;
		}
		
		for (int i = 1; i <= p; ++i)
			printf("%d\n", res[i]);
	}
}
