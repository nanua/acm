#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, a[maxn];
ld sum, inv, s[maxn];

pii px, bit[maxn<<2];

pii bit_sum(int x) {
	pii ret = pii(0, 0);
	for (; x; x -= x&-x)
		ret.fi += bit[x].fi, ret.se += bit[x].se;
	return ret;
}

void bit_ins(int x, int v) {
	for (; x <= n; x += x&-x)
		bit[x].fi += v, bit[x].se ++;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = n; i >= 1; --i) {
		px = bit_sum(a[i]);
		sum -= (s[i] += s[i+1] + px.fi);
		inv += px.se;
		bit_ins(a[i], n-i+1);
	}

	for (int i = 1; i <= n; ++i)
		sum += double(n-i+1) * (i-1) * i / 4;

	cout << fixed << setprecision(15) << inv + 2 * sum / n / (n+1);
}
