#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, a[maxn], v[maxn];
pii f[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], f[i] = pii(inf, inf);
	f[0] = pii(0, -inf);
	
	for (int i = 0; i < n; ++i) {
		for (int j = i+1, t = 1; j <= n; ++j, ++t) {
			v[t] = a[j] - t + 1;
			sort(v+1, v+t+1);
			if (f[i].se <= v[(t+1)/2] + t/2 - t) {
				ll sum = 0;
				for (int k = 1; k <= t; ++k) sum += abs(v[(t+1)/2] - v[k]);
				f[j] = min(f[j], pii(f[i].fi+sum, v[(t+1)/2] + t/2));
			}			
		}
	}
	
	cout << f[n].fi << endl;
}
