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
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int T, n, sz;
ll k, a[maxn];
queue<ll> q1, q2;

inline ll get_front(queue<ll> &q) {
	if (!sz(q)) return INF;
	return q.front();
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	for (scanf("%d\n", &T); T; T--) {
		gint(n), gint(k);
		for (int i = 1; i <= n; ++i) gint(a[i]);
		
		int L = 2, R = n, ans;
		while (L <= R) {
			int mid = (L + R) >> 1;
			ll cost = 0;

			sort(a+1, a+n+1);
			while (sz(q1)) q1.pop(); while (sz(q2)) q2.pop();
			for (int j = n; (j-1) % (mid-1) != 0; ++j) q1.push(0);
			for (int i = 1; i <= n; ++i) q1.push(a[i]); 

			while (sz(q1) + sz(q2) > 1 && cost <= k) {
				ll tot = 0;
				for (int i = 1; i <= mid; ++i) {
					ll x = get_front(q1);
					ll y = get_front(q2);
					if (x < y)
						tot += x, q1.pop();
					else
						tot += y, q2.pop();					
				}

				cost += tot, q2.push(tot);
			}
			if (cost <= k) R = (ans = mid) - 1;
			else L = mid+1;
		}

		printf("%d\n",ans);
	}
}
 
