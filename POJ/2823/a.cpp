#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
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

const lint maxn = 1e6+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar(), int sig = 1) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, k, maxhd, maxtl, minhd, mintl;
arrn a, amax, amin, qmax, qmin;

inline void add_val(int *q, int sig, int pos, int &hd, int &tl) {
	while (hd <= tl && a[q[tl]] * sig <= a[pos] * sig) tl--;
	q[++tl] = pos;
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (~scanf("%d %d", &n, &k)) {
		maxtl = mintl = 0;
		maxhd = minhd = 1;
		
		for (int i = 1; i <= n; ++i) gint(a[i]);
		
		for (int i = 1; i < k; ++i)
			add_val(qmax, 1, i, maxhd, maxtl), add_val(qmin, -1, i, minhd, mintl);

		for (int i = k; i <= n; ++i) {
			while (maxhd <= maxtl && i - qmax[maxhd] + 1 > k) ++maxhd;
			while (minhd <= mintl && i - qmin[minhd] + 1 > k) ++minhd;

			add_val(qmax, 1, i, maxhd, maxtl), add_val(qmin, -1, i, minhd, mintl);
			
			amax[i-k+1] = a[qmax[maxhd]], amin[i-k+1] = a[qmin[minhd]];
		}

		for (int i = 1; i <= n-k+1; ++i) printf("%d%c", amin[i], (i != n-k+1 ? ' ' : '\n'));
		for (int i = 1; i <= n-k+1; ++i) printf("%d%c", amax[i], (i != n-k+1 ? ' ' : '\n'));
	}	
}
 
