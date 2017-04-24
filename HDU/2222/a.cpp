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

#define R "%d"
#define RL "%I64d"
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

#define For(x, l, r) for (ll x = (l), end = (r); x <= end; ++x)
#define Rof(x, l, r) for (ll x = (l), end = (r); x >= end; --x)
#define Edge(x, y) for (ll x = la[y]; x; x = nt[x])
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
const lint maxn = 2e5+50, maxm = 1e6+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 26;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];

lint gint(lint ret = 0, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret;
}

class ac_auto {
public:
	arrm f, q;	
	lint sz, p[maxm][sigma];
	lint ed[maxm], vis[maxm], stk[maxm], cnt;

	void init() {
		For (i, 1, sz) Clr(p[i], 0);
		Clr(f, 0), Clr(ed, 0), Clr(vis, 0), Clr(stk, 0);
		cnt = 0, f[sz = 1] = 1;
	};

	void ins(char *s, int idx, int c = 1) {
#define cur p[c][s[i]-'a']
		for (int i = 0; s[i]; ++i)
			c = (cur ? cur : cur = ++sz);
		stk[c]++, ed[c] = idx;			
	}

	int jump(int x, int i) {
		for (; x != 1; x = f[x])
			if (p[x][i]) return p[x][i];
		return p[x][i] ? p[x][i] : 1;
	}

	void getfail() {
		int fr = 0, tl = 0;
		For (i, 0, sigma-1)
			if (p[1][i]) f[q[++tl] = p[1][i]] = 1;

		while (++fr <= tl) {
			int x = q[fr];
			For (i, 0, sigma-1) {
				int &c = p[x][i];
				if (c) f[q[++tl] = c] = jump(f[x], i);
			}				
		}
	}

	void match(char *s, lint c = 1) {
		for (int i = 0; s[i]; ++i) {
			c = cur ? cur : jump(f[c], s[i]-'a');
			for (int t = c; t != 1; t = f[t])
				if (ed[t]) cnt += (1-vis[ed[t]])*stk[t], vis[ed[t]] = 1;
		}
		cout << cnt << endl;
	}
}ac;

lint T, n;
char str[maxm];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	for (T = gint(); T; T--) {
		ac.init();
		n = gint();
		For (i, 1, n)
			scanf("%s\n", str), ac.ins(str, i);

		ac.getfail();

		scanf("%s", str);
		ac.match(str);
	}
}
