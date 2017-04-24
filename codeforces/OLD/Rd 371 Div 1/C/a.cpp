#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

set<int> rig;
set<int, greater<int> > lef;

void maintain(int x) {
	lef.insert(x), suml += x;
	while (lef.size() - rig.size() >= 2) {
		suml -= *lef.begin(), sumr += *lef.begin();
		rig.insert(*lef.begin());
		lef.erase(lef.begin());
	}	
}
inline ll calc(int s, int t) {
	ll x = *lef.begin();
	return pii(abs(suml - x*lef.size()) + abs(sumr - x*rig.size()), );
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = a[i] - i;

	memset(f, 0x3f, sizeof(f));
	f[1] = pii(0, a[1]);
	for (int i = 1; i <= n; ++i) {
		lef.clear(), rig.clear(), suml = sumr = 0;
		for (int j = i+1; j <= n; ++j) {
			maintain(j);
			if (f[i].se < a[j])
				f[j] = min(f[j], calc(i+1, j));
		}
	}
	
	cout << f[n].fi << endl;
}
