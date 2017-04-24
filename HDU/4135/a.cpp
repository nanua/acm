#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int vis[maxn], p[maxn], f[maxn], T, psz, kase, fsz;
ll A, B, N;

void factor(ll n) {
	fsz = 0;
	for (int i = 1; i <= psz && n != 1; ++i)
		if (n % p[i] == 0) {
			f[++fsz] = p[i];
			while (n % p[i] == 0) n /= p[i];
		}
	if (n != 1) f[++fsz] = n;
}
ll calc(int pic, int dep, ll mul) {
	if (dep == fsz+1)
		return ((pic % 2) ? -1 : 1) * (B / mul - (A-1) / mul);
	return calc(pic+1, dep+1, mul*f[dep]) + calc(pic, dep+1, mul);
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (ll i = 2; i < maxn-1; ++i)
		if (!vis[i]) {
			p[++psz] = i;
			for (ll j = i*i; j < maxn-1; j += i) vis[j] = 1;
		}
	for (cin >> T; T; T--) {
		cin >> A >> B >> N;
		factor(N);
		printf("Case #%d: %lld\n",++kase, calc(0, 1, 1));
	}
}
