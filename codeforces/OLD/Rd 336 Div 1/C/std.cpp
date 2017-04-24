#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e3+10, inf = 0x3f3f3f3f;
const int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
const char mov[] = {'N', 'E', 'W', 'S'};

int n, cnt;
char mov1[maxn], mov2[maxn];
bool f[maxn][maxn], vis[maxn][maxn];

int calc(char mv[], int cur, int m) {
	if (mv[cur] == mov[m]) return cur+1;
	if (mv[cur-1] + mov[m] == 'N'+'S' || mv[cur-1] + mov[m] == 'E'+'W') return cur-1;
	return cur;
}
bool dfs(int x, int y) {
	if (x == n && y == n) return f[x][y] = 1;
	if (vis[x][y]) return f[x][y];
	vis[x][y] = 1, cnt++;
	for (int i = 0; i < 4; ++i) {
		int nx = calc(mov1, x, i), ny = calc(mov2, y, i);
		f[x][y] |= dfs(nx, ny);
	}
	return f[x][y];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d\n", &n);
	for (int i = 1; i < n; ++i) scanf("%c\n", &mov1[i]);
	for (int i = 1; i < n; ++i) scanf("%c\n", &mov2[i]);

	puts(dfs(1, 1) ? "YES" : "NO");
	cerr << cnt;
}
