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

int p[6][6], d[5][5];
pii pre[6][6];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 0; i <= 6; ++i)
		for (int j = 0; j <= 6; ++j) p[i][j] = 1;
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j)
			cin >> p[i][j], d[i][j] = inf;
	d[5][5] = 0;
	for (int i = 1; i <= 25; ++i)
		for (int j = 1; j <= 5; ++j)
			for (int k = 1; k <= 5; ++k)
				if (p[j][k] == 0)
					for (int l = 0; l < 4; ++l)
						if (p[j+dx[l]][k+dy[l]] == 0)
							if (d[j][k] + 1 < d[j+dx[l]][k+dy[l]])
								d[j+dx[l]][k+dy[l]] = d[j][k] + 1, pre[j+dx[l]][k+dy[l]] = pii(j, k);
	
	for (pii c = pii(1, 1); c != pii(0, 0); c = pre[c.fi][c.se])
		printf("(%d, %d)\n",c.fi-1, c.se-1);
}
 
