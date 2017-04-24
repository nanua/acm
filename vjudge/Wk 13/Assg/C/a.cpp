#include <bits/stdc++.h>
using namespace std;

int n, ans[20], plc[20], vis[20];

void dfs(int d, int l, int &ct) {
	if (d == l+1)
		return void(++ct);
	for (register int i = 1; i <= l; ++i)
		if (!vis[i]) {
			for (register int j = 1; j < d; ++j)
				if (abs(j-d) == abs(plc[j] - i)) goto gt;
			vis[i] = 1, plc[d] = i;
			dfs(d+1, l, ct);
			vis[i] = 0, plc[d] = 0;
		gt:;
		}
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (int i = 1; i <= 14; ++i) dfs(1, i, ans[i]);
	
	while (cin >> n, n) cout << ans[n] << endl;
}
