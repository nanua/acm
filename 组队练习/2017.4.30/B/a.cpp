#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;

const int maxn = 2e5+50, maxm = 1e5+50;

pii d[maxn];
int n;
ll ans;

bool cmp(pii x, pii y) {
	return max(x.fi, x.se+y.fi) < max(y.fi, y.se+x.fi);
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> d[i].fi >> d[i].se;
	sort(d+1, d+n+1, cmp);

	ll tot = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, d[i].fi+tot);
		tot += d[i].se;
	}

	cout << ans;
}
