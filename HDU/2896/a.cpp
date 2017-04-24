#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define R "%d"
#define RL "%lld"
#define RD "%lf"
#define W "%.8lf"

#define Clr(x, y) memset(x, y, sizeof(x))
#define Cpy(x, y) memcpy(x, y, sizeof(y))
#define All(x) x.begin(), x.end()
#define Sqr(x) ((x) * (x))
#define Sz(x) ((LL)x.size())

#define Mk make_pair
#define Pb push_back
#define Pk pop_back
#define Fr first
#define Se second

#define For(x, l, r) for (lint x = (l), end = (r); x <= end; ++x)
#define Rof(x, l, r) for (lint x = (l), end = (r); x >= end; --x)
#define Edge(x, y) for (lint x = la[y]; x; x = nt[x])
#define Add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define Add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define Lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> MI;
typedef pair <lint, lint> PI;
typedef set <lint> SI;
typedef vector <lint> VI;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 128;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];

lint gint(lint ret = 0, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret;
}

int n, m;
char str[maxn];

class ac_auto {
public:

	int p[maxm][sigma], f[maxn], q[maxm], cnt, sz;
	bitset<501> ed[maxm];

	void init() {
		For (i, 1, sz) Clr(p, 0), ed[i].reset(), f[i] = 00;
		cnt = 0, sz = 1;
	}

	void ins(char *s, int idx, int c = 1) {
#define cur p[c][s[i]-'a']
		for (int i = 0; s[i]; ++i)
			c = cur ? cur : cur = ++sz;
		ed[c][idx] = 1;
	}

	void getfail() {
		int fr = 0, tl = 0;
		For (i, 0, sigma-1)
			p[1][i] ? f[q[++tl] = p[1][i]] = 1 : p[1][i] = 1;

		while (++fr <= tl) {
			int x = q[fr];
			ed[x] |= ed[f[x]];
			For (i, 0, sigma-1) {
				int &c = p[x][i];
				c ? f[q[++tl] = c] = p[f[x]][i] : c = p[f[x]][i];
			}
		}
	}

	void match(char *s, int idx, int c = 1) {
		bitset<501> res;
		for (int i = 0; s[i]; ++i) res |= ed[c = cur];

		if (res.count() != 0) {
			printf("web %d:", idx);
			For (i, 1, n) if (res[i] == 1) printf(" " R, i);
			puts("");
			cnt++;
		}
	}
}ac;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while (~scanf(R, &n)) {
		ac.init();
		For (i, 1, n)
			scanf("%s", str), ac.ins(str, i);

		ac.getfail();
		m = gint();
		For (i, 1, m)
			scanf("%s", str), ac.match(str, i);

		printf("total: "  R, ac.cnt);
	}
}

