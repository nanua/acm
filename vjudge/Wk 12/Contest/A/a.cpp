#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int T ,n, m, a, b;
bool vis[30][30];
ll f[30][30];

ll dfs(int x, int y) {
	if (x < 0 || y < 0 || x > n || y > m || (x == a && y == b)) return 0;
	if ((abs(a-x) == 1 && abs(b-y) == 2) || (abs(a-x) == 2 && abs(b-y) == 1)) return 0;
	if (vis[x][y]) return f[x][y];
	if (x == n && y == m) return 1;
	vis[x][y] = 1;
	return f[x][y] = dfs(x+1, y) + dfs(x, y+1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		cin >> n >> m >> a >> b;
		a++, b++, n++, m++;
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));
		cout << dfs(1, 1) << endl;
	}
}
