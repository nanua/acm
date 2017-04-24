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

int _max[10][256][256], _min[10][256][256], lg[256];
int n, m, k, b;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (int i = 2; i < 256; ++i) lg[i] = lg[i>>1] + 1;
	
	while (~scanf("%d %d %d",&n, &b, &k)) {
		clr(_max, -0x3f), clr(_min, 0x3f);
			
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				gint(_max[0][i][j]), _min[0][i][j] = _max[0][i][j];

		for (int e = 1; e <= 8; ++e)
			for (int i = 1; i + (1<<e) - 1 <= n; ++i)
				for (int j = 1; j + (1<<e) - 1 <= n; ++j)
					for (int x = 0; x <= 1; ++x)
						for (int y = 0; y <= 1; ++y) {
							_max[e][i][j] = max(_max[e][i][j], _max[e-1][i+x*(1<<(e-1))][j+y*(1<<(e-1))]);
							_min[e][i][j] = min(_min[e][i][j], _min[e-1][i+x*(1<<(e-1))][j+y*(1<<(e-1))]);
						}

		for (int r, c; k--; ) {
			gint(r), gint(c);

			int e = lg[b], Max = -inf, Min = inf, dr[] = {r, r+b-(1<<e)}, dc[] = {c, c+b-(1<<e)};
			
			for (int x = 0; x <= 1; ++x)
				for (int y = 0; y <= 1; ++y) {
					Max = max(Max, _max[e][dr[x]][dc[y]]);
					Min = min(Min, _min[e][dr[x]][dc[y]]);
				}
			printf("%d\n", Max - Min);
		}					
	}
}
