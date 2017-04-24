#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, n, dsz, a[maxn], tmp[maxn], tmq[maxn], dsc[maxn];
ll ans;

inline int bisearch(int q) {
	return n - (lower_bound(tmp+1, tmp+n+1, q) - tmp) + 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif

	while(scanf("%d",&n) != EOF) {
		ans = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for (int d = 10; d <= int(1e9); d *= 10){
			for (int i = 1; i <= n; ++i) dsc[i] = tmp[i] = a[i] % d;
			for (int i = 1; i <= n; ++i) tmq[i] = d - tmp[i];
			sort(tmp+1, tmp+n+1);
			
			for (int i = 1; i <= n; ++i)
				ans += bisearch(tmq[i]) - (dsc[i] >= tmq[i]);
		}
		cout << ans / 2 << endl; 
	}	
}
