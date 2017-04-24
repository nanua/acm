#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

set<int> S;
map<int, int> M;
int n, a[maxn], b[maxn], f[maxn], seg[maxn<<4], tag[maxn<<4];

inline void push_down(int x) {
	if (!tag[x]) return;
	seg[x<<1] = seg[x<<1|1] = tag[x];
	tag[x<<1] = tag[x<<1|1] = tag[x];
	tag[x] = 0;
}
int seg_qer(int x, int l, int r, int p) {
	push_down(x);
	if (l == r) return seg[x];
	
	int mid = (l + r) >> 1;
	
	if (p <= mid) return seg_qer(x<<1, l, mid, p);
	else return seg_qer(x<<1|1, mid+1, r, p);
}

void seg_mod(int x, int l, int r, int lx, int rx, int k) {
	if (lx > rx) return;
	push_down(x);
	if (lx == l && rx == r) return void(seg[x] = tag[x] = k);

	int mid = (l + r) >> 1;

	seg_mod(x<<1, l, mid, lx, min(mid, rx), k);
	seg_mod(x<<1|1, mid+1, r, max(mid+1, lx), rx, k);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
	sort(b+1, b+1+n);
	for (int i = 1; i <= n; ++i) M[b[i]] = i;

	S.insert(0), S.insert(n+1);
	
	for (int i = 1; i <= n; ++i) {
		set<int>::iterator it = S.lower_bound(M[a[i]]);
		int r = *it, l = *(--it);
		f[i] = seg_qer(1, 1, n, M[a[i]]);
		seg_mod(1, 1, n, l+1, r-1, a[i]);
		S.insert(M[a[i]]);
	}

	for (int i = 2; i <= n; ++i) cout << f[i] << " ";
}
