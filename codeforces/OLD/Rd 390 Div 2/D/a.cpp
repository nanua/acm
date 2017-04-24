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
typedef set <lint> sint;
typedef vector <lint> vint;

const ld eps = 1e-12, pi = acos(-1);
const lint maxn = 3e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int  n, k, ans, sz, qsz;
arrn l, r;
pii p[maxn<<1], q[maxn<<1];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i]; 
		p[++sz] = pii(l[i], -1), p[++sz] = pii(r[i], 1);
	}

	sort(p+1, p+sz+1);

	int L = 0, R = -1, cnt = 0;
	for (int i = 1; i <= sz; ++i) {
		if (p[i].se == -1)
			if (k ==  ++cnt)
				L = R = p[i].fi;
		if (p[i].se == 1)
			if (k == cnt--)
				R = p[i].fi, q[++qsz] = pii(L, R);
	}

	pii Max = pii(0, -1);
	for (int i = 1; i <= qsz; ++i)
		if (Max.se - Max.fi + 1 < q[i].se - q[i].fi + 1) Max = q[i];
	
	cout << Max.se - Max.fi + 1 << endl;
	if (Max.se - Max.fi + 1 == 0)
		for (int i = 1; i <= k; ++i) cout << i << " ";
	else
		for (int i = 1; i <= n && k >= 1; ++i)
			if (l[i] <= Max.fi && Max.se <= r[i])
				k--, cout << i << " ";
}

