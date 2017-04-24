#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int maxn = 1e5 + 10;

int n, h, tot, ans, cs;
int f[maxn], t[maxn], d[maxn], sty[maxn], ans_t[maxn];
multiset<pii, greater<pii> > q;

int main() {
	while (cin >> n >> h, n) {
		h *= 12, ++cs;
		// if (cs > 1) cout << "\n\n";
		for (int i = 1; i <= n; ++i) cin >> f[i];
		for (int i = 1; i <= n; ++i) cin >> d[i];
		for (int i = 2; i <= n; ++i) cin >> t[i];

		ans = -1;
		for (int i = 1; i <= n; ++i) {
			h -= t[i], q.clear(), tot = 0, memset(sty, 0, sizeof(int)*(n+10));
			
			for (int j = 1; j <= i; ++j) q.insert(pii(f[j], -j));
			for (int r = h; r > 0; r--) {
				pii tmp = *q.begin();
				q.erase(q.begin());
				sty[-tmp.se]++, tot += tmp.fi;
				q.insert(pii(max(tmp.fi-d[-tmp.se], 0), tmp.se));				
			}

			if (tot > ans)
				ans = tot, memcpy(ans_t, sty, sizeof(int)*(n+10));
		}

		for (int i = 1; i <= n; ++i)
			cout << ans_t[i]*5 << (i == n ? " " : ", ");
		cout << "\nNumber of fish expected: " << ans << "\n\n";
	}
} 
