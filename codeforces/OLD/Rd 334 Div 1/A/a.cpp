#include<bits/stdc++.h>
using namespace std;
int n, k, ans;
int f[100010][2][4];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	scanf("%d\n",&n);
	for (int i = 1; i <= n; ++i){
		scanf("%1d",&k);
		int *a = f[i-1][k], *b = f[i-1][k^1], *c = f[i][k], *d = f[i][k^1];
		c[0] = b[0] + 1;
		d[0] = b[0];
		c[1] = a[1];
		d[1] = max(a[0], a[1]) + 1;
		c[2] = max(b[1], b[2]) + 1;
		d[2] = max(b[1], b[2]);
		ans = max(ans, max(*max_element(c, c+3), *max_element(d, d+3)));
	}
	cout << ans;
}
