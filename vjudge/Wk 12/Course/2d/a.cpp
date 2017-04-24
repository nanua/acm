#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n;
pair<int, int> s[maxn];
int f[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n, n) {
		for (int i = 1; i <= n; ++i) cin >> s[i].fi >> s[i].se;

		sort(s+1, s+n+1);

		memset(f, -0x3f, sizeof(f));
		f[0] = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < i; ++j)
				if (s[j].se <= s[i].fi)
					f[i] = max(f[i], f[j] + 1);

		cout << *max_element(f+1, f+n+1) << endl;
	}
}
 
