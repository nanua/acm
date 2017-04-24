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

int n, k, T, pmax, pmin, maxsz, minsz;
arrn qmax, qmin, a;

void add_ele(int x, int *q, int &sz, int dir) {
	while (sz && a[q[sz]] * dir <= a[x] * dir) sz--;
	q[++sz] = x;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	a[0] = inf, a[1] = -inf, qmax[0] = 0, qmin[0] = 1;
	
	for (scanf("%d\n", &T); T; T--) {
		gint(n), gint(k);
		for (int i = 2; i <= n+1; ++i) gint(a[i]);

		ll ans = 0;
		pmax = pmin  = 1, maxsz = minsz = 0;
		for (int i = 2, j = 1; i <= n+1; ++i) {
			add_ele(i, qmax, maxsz, 1), add_ele(i, qmin, minsz, -1);

			if (pmax >= maxsz) pmax = maxsz - 1;
			if (pmin >= minsz) pmin = minsz - 1;
			while (qmax[pmax] < j) pmax++;
			while (qmin[pmin] < j) pmin++;
			
			while (a[qmax[pmax]] - a[qmin[pmin]] >= k) {
				j++;					
				while (qmax[pmax] < j) pmax++;
				while (qmin[pmin] < j) pmin++;
			}

			ans += i-j+1;
		}

		cout << ans << endl;
	}

}
 

