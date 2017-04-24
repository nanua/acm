#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((ll)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ld eps = 1e-12, pi = acos(-1);
const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef int arrm[maxm];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

deque<pii> q;
arrn d, in, ou;
int n, c, T;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (scanf("%d\n", &T); T; T--) {
		gint(n), gint(c);
		for (int i = 2; i <= n+1; ++i) gint(d[i]);
		for (int i = n+1; i >= 2; --i) d[i] -= d[i-1];
		for (int i = 1; i <= n+1; ++i) gint(in[i]), gint(ou[i]);

		ll ans = 0;
		ans = in[1] * c;
		q.push_back(pii(in[1], c));

		for (int i = 2; i <= n+1; ++i) {
			int chg = d[i];

			for (int j = d[i]; j; )
				if (j >= q.front().se) j -= q.front().se, q.pop_front();
				else q.front().se -= j, j = 0;

			while (q.size() && q.back().fi > in[i])
				chg += q.back().se, ans -= q.back().fi * q.back().se, q.pop_back();

			q.push_back(pii(in[i], chg));
			ans += (ll)in[i] * chg;
		}

		for (; q.size(); q.pop_front())
			ans -= (ll)max(q.front().fi, ou[n+1]) * q.front().se;

		cout << ans << endl;
	}

}

