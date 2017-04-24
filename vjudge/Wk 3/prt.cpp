#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

inline ll mul_mod(ll x, ll y) { return x * y % mod; }
inline ll pow_mod(ll x, ll y) {
	ll ret = 1;
	for (; y; y >>= 1, x = mul_mod(x, x))
		if (y & 1) ret = mul_mod(ret, x);
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll p = 1, q = 4;
	cout << mul_mod(p, pow_mod(q, mod-2));
}
