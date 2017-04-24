#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, q, t, l, r, x, sz, snp;
ll f[70][70][2], g[70][2], dig[30];
int sto[70][70][2];

ll _calc_lowbit(int p, int las_1, int tgt) {
	if (p == 0) return 1LL<<(las_1-1);
	
	ll &x = f[p][las_1][tgt];	
	if (sto[p][las_1][tgt] == snp) return x;
	x = 0, sto[p][las_1][tgt] = snp;

	if (tgt)
		if (dig[p] == 1)
			x += _calc_lowbit(p-1, p, 1) + _calc_lowbit(p-1, las_1, 0);
		else
			x += _calc_lowbit(p-1, las_1, 1);
	else
		x += _calc_lowbit(p-1, p, 0) + _calc_lowbit(p-1, las_1, 0);
	return x;
}
ll calc_lowbit(ll x) {
	snp++;
	for (sz = 0; x; x >>= 1) dig[++sz] = x & 1;
	return _calc_lowbit(sz, 0, 1);
}

ll _calc_contain(int p, int tgt, int les) {
	if (p == les) return (!tgt || dig[les] == 1);

	ll &x = g[p][tgt];
	if (x >= 0) return x;
	x = 0;
	if (tgt)
		if (dig[p] == 1)
			x += _calc_contain(p-1, 1, les) + _calc_contain(p-1, 0, les);
		else
			x += _calc_contain(p-1, 1, les);
	else
		x += (_calc_contain(p-1, 0, les) << 1);
	return x;
}
ll calc_contain(ll N) {
	ll ret = 0;

	for (int i = 1; i <= 65; ++i) {
		memset(g, -1, sizeof(g));
		N = min(n, x-1+(1LL<<(i-1)));
		for (sz = 0; N > 0; N >>= 1) dig[++sz] = N & 1;
		if (sz >= i)
			ret += _calc_contain(sz, 1, i);
	}
	return ret - x + 1;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (~scanf("%lld %lld",&n,&q)) {
		for (; q; q--) {
			scanf("%lld",&t);
			if (t == 1) {
				scanf("%lld %lld",&l, &r);
				ll rhs = calc_lowbit(r);
				ll lhs = calc_lowbit(l-1);
				printf("%lld\n", rhs-lhs);
			}
			else {
				scanf("%lld",&x);
				ll ans = calc_contain(n); 
				printf("%lld\n", ans);
			}
		}
	}
}
