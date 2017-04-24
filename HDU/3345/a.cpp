#include <bits/stdc++.h>
#define mkp(x, y, z) make_pair(make_pair(x, y), z)
#define tx (x.fi.fi + dx[i])
#define ty (x.fi.se + dy[i])
#define fi first
#define se second
using namespace std;

typedef pair<pair<int, int>, int> tpi;
const int maxn = 110, inf = 0x3f3f3f3f, dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};
const char typ[] = {'Y', '.', 'T', 'R', '#', 'P',  0,  'E', '^'};
const int  cst[] = { 0,   1,   2,   3,  inf,  1 , inf, inf, -1 };

char s[maxn][maxn], mps[maxn][maxn];
int n, m, mv, T, vis[maxn][maxn];

inline int get_c(char x) {
	for (int i = 0; ; ++i) if (typ[i] == x) return cst[i];
}

void bfs(int x, int y, int mv) {
	queue<tpi> q;

	memset(vis, 0, sizeof(vis)); 
	q.push(mkp(x, y, mv));	
	vis[x][y] = 1;
	
	while (q.size()) {
		tpi x = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			tpi tmp = mkp(tx, ty, x.se - get_c(mps[tx][ty]));
			if (mps[tx][ty] == '^') tmp.se = 0;
			if (!vis[tx][ty] && tmp.se >= 0)
				q.push(tmp), vis[tx][ty] = 1, s[tx][ty] = (s[tx][ty] == 'P' ? 'P' : '*');
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d\n",&T); T; T--) {
		scanf("%d %d %d\n",&n, &m, &mv);
		for (int i = 1; i <= n; ++i) scanf("%s\n", s[i]+1);

		memcpy(mps, s, sizeof(s));

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (mps[i][j] == 'E')
					for (int k = 0; k < 4; ++k)
						if (mps[i+dx[k]][j+dy[k]] != 'Y') mps[i+dx[k]][j+dy[k]] = '^';
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (s[i][j] == 'Y') bfs(i, j, mv);


		for (int i = 1; i <= n; ++i) puts(s[i]+1);
		puts("");
	}
}
