#include <bits/stdc++.h>
using namespace std;

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
const lint maxn = 6e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 26;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> Q gint(Q ret = 0, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret;
}
int T, n, m;
arrn st, ed = {-1};
char str[maxn], tmp[maxn];

class ac_auto {
public:
	lint p[maxn][sigma], f[maxn], sz;
	ll ed[maxn];

	inline void init() {
		For (i, 1, sz)
			clr(p[i], 0), f[i] = ed[i] = 0;
		sz = 1;
	}

	void ins(char *s, int c = 1) {
#define cur p[c][s[i]-'a']
		for (int i = 0; s[i]; ++i)
			c = cur ? cur : cur = ++sz;
		ed[c]++;
	}

	void getfail() {
		int fr = 0, tl = 0, q[maxn] = {};
		For (i, 0, sigma-1)
			p[1][i] ? f[q[++tl] = p[1][i]] = 1 : p[1][i] = 1;

		while (++fr <= tl) {
			int x = q[fr];
			ed[x] += ed[f[x]];
			For (i, 0, sigma-1) {
				int &c = p[x][i];
				c ? f[q[++tl] = c] = p[f[x]][i] : c = p[f[x]][i];
			}
		}			
	}

	ll match(char *s, char *e, int c = 1, ll ret = 0) {
		for (; s != e; ++s)
			c = p[c][*s-'a'], ret += ed[c];
		return ret;
	}
}ac;
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n", &T); T; T--) {
		ac.init(), clr(str, 0);
		
		scanf("%d %d\n", &n, &m);

		For (i, 1, n) {
			scanf("%s", tmp);
			st[i] = ed[i-1]+1, ed[i] = st[i] + strlen(tmp);
			memcpy(str+st[i], tmp, sizeof(char)*strlen(tmp));
		}

		For (i, 1, m) {
			scanf("%s", tmp);
			ac.ins(tmp);
		}

		ac.getfail();

		For (i, 1, n)
			printf("%lld\n", ac.match(str+st[i], str+ed[i]));
	}
}
 

