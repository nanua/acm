#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> bst;

template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

bst seg[maxn<<3];
int n, q;
arrn a;

void build(int x, int l, int r) {
	for (int i = l; i <= r; ++i)
		seg[x].insert(i);
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(x<<1, l, mid), build(x<<1|1, mid+1, r);
}

int seg_qer(int x, int l, int r, int L, int R, int v, int op) {
	if (L > R) return 0;
	if (l == L && r == R) {
		if (op == 1) return seg[x].order_of_key(v);
		if (op == -1) return seg[x].size() - seg[x].order_of_key(v);
	}

	int mid = (l + r) >> 1;
	int Lret = seg_qer(x<<1, l, mid, L, min(mid, R), v, op);
	int Rret = seg_qer(x<<1|1, mid+1, r, max(mid+1, L), R, v, op);

	return Lret + Rret;
}

void seg_mod(int x, int l, int r, int p1, int p2) {
	if ((l <= p1 && p1 <= r) && !(l <= p2 && p2 <= r))
		seg[x].erase(a[p2]), seg[x].insert(a[p1]);
	if (!(l <= p1 && p1 <= r) && (l <= p2 && p2 <= r))
		seg[x].erase(a[p1]), seg[x].insert(a[p2]);

	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p1 <= mid)
		seg_mod(x<<1, l, mid, p1, p2);
	else
		seg_mod(x<<1|1, mid+1, r, p1, p2);
}
void D(const bst &t) {
	for (bst::iterator it = t.begin(); it != t.end(); ++it)
		cerr << *it << " ";
	cerr << endl << endl << endl;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	gint(n), gint(q);
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) a[i] = i;

	ll tot = 0;
	for (int i = 1, l, r; i <= q; ++i) {
		gint(l), gint(r);
		if (l > r) swap(l, r);
		if (a[l] < a[r]) tot++;
		if (a[l] > a[r]) tot--;

		tot -= seg_qer(1, 1, n, l+1, r-1, a[r], -1);
		tot -= seg_qer(1, 1, n, l+1, r-1, a[l], 1);
		swap(a[l], a[r]);
		tot += seg_qer(1, 1, n, l+1, r-1, a[r], -1);
		tot += seg_qer(1, 1, n, l+1, r-1, a[l], 1);
		seg_mod(1, 1, n, r, l);
		seg_mod(1, 1, n, l, r);

		cout << tot << endl;
	}
}

