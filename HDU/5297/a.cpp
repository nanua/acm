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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];

const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61}; // 18

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

ll n;
int cof[100], Max[100], Cof[100][100];
int r, T;
int cnt = 0;

void dfs(int c, int s, int e, int mx) {
	if (e > 62) return;
	if (c == 18) {
		cof[e] = (s % 2 ? -1 : 1);
		Max[e] = mx;
		return;
	}
	dfs(c+1, s+1, e*pri[c], pri[c]);
	dfs(c+1, s , e, mx);
}
ll calc(ll x) {
	ll ret = 0;
	for (int i = 1; i <= Cof[r][0]; ++i){
		ll t = pow((ld)x+0.5, 1.0/abs(Cof[r][i]))-1LL;
			if (Cof[r][i] > 0)
				ret += t;
			else
				ret -= t;
		}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	memset(Max, 0x3f, sizeof(Max));
	dfs(0, 0, 1, 0);

	for (int i = 2; i <= 62; ++i)
		for (int j = 1; j <= 62; ++j)
			if (Max[j] <= i)
				Cof[i][++Cof[i][0]] = cof[j] * j;

	for (gint(T); T--; ) {
		gint(n), gint(r);

		ll L = n, ans;
		while ((ans = calc(L)) != n)
			L += (n-ans);
		printf("%lld\n", L);
	}
}

