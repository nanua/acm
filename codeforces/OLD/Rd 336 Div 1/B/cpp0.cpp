#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010, inf = 0x3f3f3f3f;

int n, c[maxn],f[maxn][maxn];

int dfs(int l, int r) {
	if (l >= r) return f[l][r] = r-l+1;
	if (f[l][r] != inf) return f[l][r];

	f[l][r] = min(f[l][r], dfs(l+1, r) + 1);
	if (c[l] == c[l+1]) f[l][r] = min(f[l][r], dfs(l+2, r)+1);
	for (int i = r; i >= l+2; --i)
		if (c[l] == c[i]) f[l][r] = min(f[l][r], dfs(l+1, i-1) + dfs(i+1, r));

	return f[l][r];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif

	cin >> n;
	for (int i = 1 ; i <= n; ++i) cin >> c[i];
	memset(f, 0x3f, sizeof(f));
	
	cout << dfs(1, n) << endl;

}
