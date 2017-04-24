#include<bits/stdc++.h>
using namespace std;
int n, ans;
int a[1010], b[1010], f[1010][2];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("cmp", "w", stdout);
#endif
	
	scanf("%d\n",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%1d", &a[i]);

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j){
			memcpy(b, a, sizeof(a));
			for (int k = i; k <= j; ++k) b[i] ^= 1;
			memset(f, 0, sizeof(f));
			for (int k = 1; k <= n; ++k) {
				f[k][b[k]] = max(f[k-1][b[k]], f[k-1][b[k]^1] + 1);
				f[k][b[k]^1] = f[k-1][b[k]^1];
				ans = max(ans, f[k][b[k]]);
			}
			
		}
	cout << ans;
}
