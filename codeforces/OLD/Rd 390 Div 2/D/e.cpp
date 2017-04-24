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
const lint maxn = 6e5+50, maxm = 1e5+50, inf = (lint)0x3f3f3f3f, mod = (lint)1e9 + 7, sigma = 129;
const ll INF = (ll)1e17;

typedef lint arrn[maxn];
typedef lint arrm[maxm];


template<class Q> void gint(Q &ret, char ch = getchar()) {
	while (!isdigit(ch)) ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
}

int  n, k;
arrn l, r;
pii s[maxn];
multiset<int> st;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> r[i], s[i] = pii(l[i], r[i]);

	sort(s+1, s+n+1);
	int tl = 0, tr = -1;
	for (int i = 1; i <= n; ++i) {
		st.insert(s[i].se);
		while ((st.size() && *st.begin() < s[i].fi) || st.size() > k) st.erase(st.begin());
		
		if (st.size() >= k && *st.begin() - s[i].fi > tr - tl)
			tl = s[i].fi, tr = *st.begin();
	}
	
	cout << tr - tl + 1 << endl;
	if (tr - tl + 1 == 0)
		for (int i = 1; i <= k; ++i) cout << i << " ";
	else
		for (int i = 1; i <= n && k >= 1; ++i)
			if (l[i] <= tl && tr <= r[i])
				k--, cout << i << " ";
}

