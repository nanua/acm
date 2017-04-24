#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int n, m, t, stx, sty, edx, edy;
char grd[60][60];

bool dfs(int x, int y, int d) {
	if (x == edx && y == edy) return d == t;
	if (d > t || (((x+y+t-d)&1) != ((edx+edy)&1))) return 0;

	char ch = grd[x][y];
	grd[x][y] = 'X';
	for (int i = 0; i < 4; ++i) {
		int tx = x + dx[i], ty = y + dy[i];
		if (1 <= tx && tx <= n && 1 <= ty && ty <= m)
			if (grd[tx][ty] != 'X')
				if (dfs(tx, ty, d+1)) return 1;
	}
	grd[x][y] = '.';
	return 0;
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	
	while (~scanf("%d %d %d",&n, &m, &t), n) {
		for (int i = 1; i <= n; ++i) scanf("%s", grd[i]+1);

		bool succ = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (grd[i][j] == 'S') stx = i, sty = j;
				if (grd[i][j] == 'D') edx = i, edy = j;
			}

		succ = dfs(stx, sty, 0);
		puts(succ ? "YES" : "NO");
	}
}
