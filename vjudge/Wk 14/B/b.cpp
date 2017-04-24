#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

ll n, q, t, l, r, x, sz, snp;

ll calc_lowbit(ll x) {
	ll ret = 0, t = x;
	for (int i = 0; i <= 60 && t; ++i, t >>= 1)
		ret += ((x>>(i+1))+1-((x&((1LL<<(i+1))-1))<(1LL<<i))) * (1LL<<i);
	return ret;			  
}

ll calc_contain(ll N) {
	ll ret = 0;
	for (int i = 0; i <= 60; ++i) {
		N = min(n, x-1+(1LL<<i));
		ret += (N>>(i+1))+1-((N&((1LL<<(i+1))-1))<(1LL<<i));
	}
	return ret - x + 1;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n >> q) {
		for (; q; q--) {
			cin >> t;
			if (t == 1) {
				cin >> l >> r;
				ll rhs = calc_lowbit(r);
				ll lhs = calc_lowbit(l-1);
				cout << rhs - lhs << endl;
			}
			else {
				cin >> x;
				ll ans = calc_contain(n); 
				cout << ans << endl;
			}
		}
	}
}
