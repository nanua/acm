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
typedef pair <lint, lint> pii;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 1e6+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}
int n;
arrn a, id, bit;
int cmp(int x, int y) {
	return a[x] > a[y];
}
void bit_ins(int p) {
	for (; p <= n; p += lowbit(p)) bit[p]++;
}
int bit_req(int p, int ret = 0) {
	for (; p; p -= lowbit(p)) ret += bit[p];
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; ++i)
			gint(a[i]), id[i] = i, bit[i] = 0;

		sort(id+1, id+n+1, cmp);

		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			int tid = id[i] - bit_req(id[i]);
			ans += n-i-tid+1;
			bit_ins(id[i]);
		}

		cout << ans << endl;
	}
		
}
 
