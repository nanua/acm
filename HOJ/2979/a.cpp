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
#define pd(x) (x != '@' && x != '*' && x != 'S' && x != 'D')
#define Dx x+dx[i]
#define Dy y+dy[i]
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e2 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int dx[] = {-1, -1, 0, +1, +1, 0}, dy[] = {-1, 0, +1, +1, 0, -1};
int ks, n, t, f[maxn][maxn], q[maxn*maxn][2];;
char s[maxn][maxn];

int bfs(int x, int y) {
	int fr = 0, tl = 0;
	++tl, q[tl][0] = x, q[tl][1] = y, f[x][y] = 0;
	while (++fr <= tl) {
		x = q[fr][0], y = q[fr][1];
		for (int i = 0; i < 6; ++i) {
			if (s[Dx][Dy] == '@' && f[Dx][Dy] == inf) ++tl, q[tl][0] = Dx, q[tl][1] = Dy, f[Dx][Dy] = f[x][y] + 1;
			if (s[Dx][Dy] == 'D') return f[x][y] + 1;
		}
	}
	return inf;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d %d\n",&n, &t) == 2) {
		memset(s, 0, sizeof(s));
		memset(f, 0x3f, sizeof(f));
		
		for (int i = 1, j, k, l; i <= n; ++i) {
			gets(s[i]+1);
			for (j = 1, k = 0, l = strlen(s[i]+1); j <= l; ++j)
				if (!pd(s[i][j])) s[i][++k] = s[i][j];
			for (j = k+1; j <= l; ++j) s[i][j] = 0;
		}
		
		int ans = inf;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1, l = strlen(s[i]+1); j <= l; ++j)
				if (s[i][j] == 'S') ans = bfs(i, j);

		if (ks >= 1) puts("");
		if (ans <= t)
			if (ans != 1)
				printf("Maze #%d :\nHurry up, You need %d minutes to escape!\n", ++ks, ans);
			else
				printf("Maze #%d :\nHurry up, You need %d minute to escape!\n", ++ks, ans);
		else
			printf("Maze #%d :\nOh No, I'm afraid that you don't have enough time to escape!\n", ++ks);
	}
}
