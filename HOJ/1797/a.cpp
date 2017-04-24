#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int n, m;
char mps[25][25];
int vis[25][25];

void dfs(int x, int y) {
	if (mps[x][y] == '#' || vis[x][y]) return;
	vis[x][y] = 1;
	for (int i = 0; i <= 3; ++i) dfs(x+dx[i], y+dy[i]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d %d\n",&n, &m), n) {
		swap(n, m);
		for (int i = 1; i <= n; ++i) scanf("%s\n", mps[i]+1);
		for (int i = 1; i <= n; ++i) mps[i][0] = mps[i][m+1] = '#';
		for (int i = 1; i <= m; ++i) mps[0][i] = mps[n+1][i] = '#';
		
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (mps[i][j] == '@') dfs(i, j);

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) ans += vis[i][j];

		cout << ans << endl;
	}
} 
