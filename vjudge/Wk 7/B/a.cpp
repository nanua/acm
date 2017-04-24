#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, n, dsz, a[maxn], tmp[maxn], tmq[maxn], dsc[maxn], sz[maxn<<3];
ll ans;

void build(int x, int l, int r) {
	sz[x] = 0;
	if (l == r) return;
	int mid = (l+r) >> 1;
	build(x<<1, l, mid), build(x<<1|1, mid+1, r);	
}
inline int bisearch(int x, int l, int r, int q) {
	if (r < q) return 0;
	if (l >= q) return sz[x];
	int mid = (l + r) >> 1;
	return bisearch(x<<1, l, mid, q) + bisearch(x<<1|1, mid+1, r, q);
}
inline void insertion(int x, int l, int r, int q) {
	if (l == r) return void(sz[x]++);
	int mid = (l+r) >> 1;
	if (q <= mid) insertion(x<<1, l, mid, q);
	else insertion(x<<1|1, mid+1, r, q);
	sz[x] = sz[x<<1] + sz[x<<1|1];
}
int getpos(int x) {
	return lower_bound(dsc+1, dsc+dsz+1, x) -  dsc;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	while(scanf("%d",&n) != EOF) {
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		ans = 0;
		for (int d = 10; d <= int(1e9); d *= 10){
			for (int i = 1; i <= n; ++i) tmp[i] = a[i] % d;
			for (int i = 1; i <= n; ++i) tmq[i] = d - tmp[i];
			dsz = 0;
			for (int i = 1; i <= n; ++i) dsc[++dsz] = tmp[i];
			sort(dsc+1, dsc+dsz+1);
			dsz = unique(dsc+1, dsc+dsz+1) - dsc - 1;

			build(1, 1, dsz);
			
			for (int i = 1; i <= n; ++i) {
				ans += bisearch(1, 1, dsz, getpos(tmq[i]));
				insertion(1, 1, dsz, getpos(tmp[i]));
			}
		}
		printf("%lld\n", ans);
	}	
}
