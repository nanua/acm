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
#define RL "%I64d"
#define RD "%lf"
#define W "%.8lf"

#define clr(x, y) memset(x, y, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((LL)x.size())

#define mk make_pair
#define pb push_back
#define pk pop_back
#define fi first
#define se second

#define For(x, l, r) for (register lint x = (l), end = (r); x <= end; ++x)
#define Rof(x, l, r) for (lint x = (l), end = (r); x >= end; --x)
#define For_edge(x, y) for (lint x = la[y]; x; x = nt[x])
#define Add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define Add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define Lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
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
	
	int p[maxm][sigma], ed[maxn], f[maxn], q[maxm], cnt, sz;
	
	void init() {
		For (i, 1, sz) clr(p[i], 0), ed[i] = f[i] = 0;
		cnt = 0, sz = 1;
	}
	
	inline void ins(char *s, int idx, int c = 1) {
#define cur p[c][int(s[i])]
		for (int i = 0; s[i]; ++i)
			c = cur ? cur : cur = ++sz;
		ed[c] = idx;
	}
	
	void getfail() {
		register int fr = 0, tl = 0;
		For (i, 0, sigma-1)
			if (p[1][i]) f[q[++tl] = p[1][i]] = 1;
		
		while (++fr <= tl) {
			int x = q[fr];
			For (i, 0, sigma-1) {
				int &c = p[x][i];
				if (!c) continue;
				q[++tl] = c;
				for (f[c] = f[x]; f[c] != 1 && !p[f[c]][i]; f[c] = f[f[c]]);				
				if (p[f[c]][i]) f[c] = p[f[c]][i];
			}				
		}
	}

	void match(char *s, int idx, register int c = 1) {
		bool res[501] = {};
		for (register int i = 0; s[i]; ++i) {
			for (; c != 1 && !cur; c = f[c]);
			if (cur) c = cur;
			for (int j = c; j != 1; j = f[j])
				if (ed[j]) res[ed[j]] = 1, res[0] = 1;
		}
			
		if (res[0] != 0) {
			printf("web %d:", idx);
			For (i, 1, n)
				if (res[i]) printf(" " R, i);
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
	
	n = gint();
	ac.init();
	For (i, 1, n)
		scanf("%s\n", str), ac.ins(str, i);
	
	ac.getfail();
	m = gint();
	For (i, 1, m)
		scanf("%s\n", str), ac.match(str, i);
	
	printf("total: "  R "\n", ac.cnt);
	//cerr << (sizeof(ac.p)+sizeof(ac.ed))/1048576.0 << endl;
}
