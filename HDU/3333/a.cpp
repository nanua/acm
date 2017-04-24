#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int n, m, T;
// arrn a, pre, id;
arrm ans, a, pre, id;
pii q[maxn];
ll v[maxn<<3];
map<int, int> mps;

bool cmp(int x, int y) {
	return q[x].se > q[y].se;
}
void seg_ins(int x, int l, int r, int p) {
	if (p == 0) return;
	if (l == r)
		{ v[x] = a[p]; return; }
	int mid = (l + r) >> 1;
	p <= mid ? seg_ins(x<<1, l, mid, p) : seg_ins(x<<1|1, mid+1, r, p);
	v[x] = v[x<<1] + v[x<<1|1];
}
ll seg_qer(int x, int l, int r, int al, int ar) {
	if (al > ar) return 0;
	if (l == al && r == ar) return v[x];
	int mid = (l + r) >> 1;
	return seg_qer(x<<1, l, mid, al, min(ar, mid))
		+ seg_qer(x<<1|1, mid+1, r, max(mid+1, al), ar);
}

int main() {
#ifdef LOCAL
    freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (gint(T); T--; ) {
		gint(n);
		mps.clear();
		memset(v, 0, sizeof(v));

		for (int i = 1; i <= n; ++i) {
			gint(a[i]);
			pre[i] = mps[a[i]], mps[a[i]] = i;
		}
		for (map<int, int>::iterator itr = mps.begin(); itr != mps.end(); ++itr)
			seg_ins(1, 1, n, itr->se);

		gint(m);
		for (int i = 1; i <= m; ++i)
			gint(q[i].fi), gint(q[i].se), id[i] = i;
		sort(id+1, id+m+1, cmp);

		for (int i = 1, j = n; i <= m; ++i) {
			for (; j >= 1 && j > q[id[i]].se; --j)
				seg_ins(1, 1, n, pre[j]);
			ans[id[i]] = seg_qer(1, 1, n, q[id[i]].fi, q[id[i]].se);
		}

		for (int i = 1; i <= m; ++i)
			printf("%lld\n", ans[i]);
	}
}
