#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
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

arrn fac, inv;
string s;
int lef, rig;
ll ans;

ll mmod(ll x, ll y) { return x * y % mod; }
ll pmod(ll x, ll e, ll ret = 1) {
	for (; e; e >>= 1, x = mmod(x, x))
		if (e & 1) ret = mmod(ret, x);
	return ret;
}
ll comb(ll k, ll n) {
	if (k > n) return 0;
	return mmod(fac[n], mmod(inv[k], inv[n-k]));
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i <= 2e5; ++i)
		fac[i] = mmod(fac[i-1], i), inv[i] =  pmod(fac[i], mod-2);

	cin >> s;
	for (char c : s) rig += (c == ')');

	for (char c : s)
		if (c == '(') {
			lef++;
			(ans += comb(lef, lef+rig-1)) %= mod;
		}
		else
			rig--;

	cout << ans % mod;
}
