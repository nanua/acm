#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, a, b;
int d[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		cin >> a >> b;
		
		if (2*b-a < 0) {
		gt :;
			puts("0"); continue;
		}
		if (2*b-a == 0) {
			for (int i = 1; i <= 9; ++i)
				if (a*i == b*(2*i-9*(2*i/10))) {
					printf("%d\n", i); break;
				}
			continue;
		}
		int lcm = (2*b-a)*9*b / __gcd(2*b-a, 9*b);

		int l = lcm / (9*b), s = lcm / (2*b-a), ts = s-5*l, dsz = 0;

		if (ts < 0) goto gt;
		
		for (int i = 1; ts > 0; ++i, ts -= min(ts, 4)) d[++dsz] = min(ts, 4);

		for (int i = 1; i <= l; ++i) d[i] += 5;

		for (int i = max(l, dsz); i >= 1; --i) cout << d[i];

		puts("");
	}
}

