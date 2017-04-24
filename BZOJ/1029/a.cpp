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

multiset<pii, greater<pii> > s;
int n;
pii p[maxn];

bool cmp(const pii &x, const pii &y) {
	return x.se < y.se;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n);
	for (int i = 1; i <= n; ++i) gint(p[i].fi), gint(p[i].se);

	sort(p+1, p+n+1, cmp);

	for (int i = 1, cur = 0; i <= n; ++i)
		if (cur + p[i].fi <= p[i].se)
			cur += p[i].fi, s.insert(p[i]);
		else if (s.size() && s.begin()->fi > p[i].fi)
			cur -= s.begin()->fi - p[i].fi, s.erase(s.begin()), s.insert(p[i]);

	cout << s.size();
}
 
