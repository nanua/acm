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

#define add_edge(x, y) (to[++edg] = y, nt[edg] = la[x], la[x] = edg)
#define add_wedge(x, y, w) (to[++edg] = y, wgt[edg] = w, nt[edg] = la[x], la[x] = edg)
#define lowbit(x) ((x) & (-x))

typedef int lint;
typedef long long ll;
typedef long double ld;

typedef map <lint, lint> mii;
typedef pair <lint, lint> pii;
typedef pair <pii, lint> tpi;
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 2e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

class bign{
public:
	int d[63];
	void set(int p) {
		d[p/32] |= 1<<(p%32);
	}

	bool compare(const bign &x) {
		for (int i =  62; i >= 0; --i)
			if (d[i] != x.d[i]) return d[i] < x.d[i];
		return 0;
	}

	void output(int l = 62) {
		for (; l > 0 && d[l] == 0; --l);
		for (; l >= 0; --l) cout << d[l];
	}
}f[2020], tmp;

int n, sz, a[5020], t[5020];
tpi p[2020];
char str[20];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%s %d", str, &a[i]), t[i] = str[0] == 's';

	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			if (t[i] == 0 && t[j] == 1 && a[i] == a[j])
				p[++sz] = tpi(pii(j, i), a[i]);

	sort(p+1, p+sz+1);
	for (int i = 1; i <= sz; ++i)
		for (int j = 0; j < i; ++j)
			if (p[j].fi.fi < p[i].fi.se) {
				tmp = f[j], tmp.set(p[i].se);
				if (f[i].compare(tmp))
					f[i] = tmp;
			}

	f[sz].output();				
}
 
