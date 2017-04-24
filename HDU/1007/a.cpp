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

typedef int lint;
typedef long long ll;
typedef long double ld;
typedef pair <double, double> pii;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int n;
pii p[maxn], t[maxn];

bool cmp1(const pii &p1, const pii &p2) {
	return (p1.fi == p2.fi ? p1.se < p2.se : p1.fi < p2.fi);
}
bool cmp2(const pii &p1, const pii &p2) {
	return (p1.se == p2.se ? p1.fi < p2.fi : p1.se < p2.se);
}
inline double dist(const pii &p1, const pii &p2) {
	return hypot(p1.fi - p2.fi, p1.se - p2.se);
}

double nearest(int l, int r) {
	if (l == r) return INF;
	if (r - l == 1) {
		if (!cmp2(p[l], p[r])) swap(p[l], p[r]);
		return dist(p[l], p[r]);
	}

	int mid = (l + r) >> 1;

	nth_element(p+l, p+mid, p+r+1, cmp1);
	double res1 = nearest(l, mid);
	double res2 = nearest(mid+1, r);
	double res3 = INF;
		
	merge(p+l, p+mid+1, p+mid+1, p+r+1, t+l, cmp2);
	copy(t+l, t+r+1, p+l);

	for (int i = l; i <= r; ++i)
		for (int j = i + 1; j <= r && j - i < 6; ++j)
			res3 = min(res3, dist(p[i], p[j]));
	return min(res3, min(res1, res2));
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (gint(n), n) {
		for (int i = 1; i <= n; ++i) scanf("%lf %lf", &p[i].fi, &p[i].se);

		printf("%.2lf\n", nearest(1, n) / 2.0);
	}
}
 
