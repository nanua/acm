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

int n, q;
arrn lg, h, _max[21], _min[21];

void rmq_init() {
	for (int i = 1; i <= n; ++i)
		_max[0][i] = _min[0][i] = h[i];
	
	for (int j = 1; j <= 20; ++j)
		for (int i = 1; i + (1<<j) <= n+1; ++i) {
			_max[j][i] = max(_max[j-1][i], _max[j-1][i+(1<<(j-1))]);
			_min[j][i] = min(_min[j-1][i], _min[j-1][i+(1<<(j-1))]);
		}
}

void rmq_qer(int l, int r) {
	int e = lg[r-l+1];
	printf("%d\n", max(_max[e][l], _max[e][r-(1<<e)+1])
		   - min(_min[e][l], _min[e][r-(1<<e)+1]));
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (int i = 2; i < 5e4; ++i) lg[i] = lg[i>>1]+1;
	
	while (~scanf("%d %d", &n, &q)) {
		for (int i = 1; i <= n; ++i) gint(h[i]);

		rmq_init();

		for (int l, r; q--; ){
			gint(l), gint(r);
			rmq_qer(l, r);
		}
	}
}

