#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define pd(x) (x != '@' && x != '*' && x != 'S' && x != 'D')
#define inf (0x3f3f3f3f)
using namespace std;
int h, t, head, tail, countn;
queue<int> q;
int vis[410][420];
int ending[40010];
char maps[410][420], tmp[40010];
// int dx[] = {0, 0, 1, 1, -1, -1};
// int dy[] = {2, -2, 1, -1, 1, -1};

const int dx[] = {-1, -1, 0, +1, +1, 0}, dy[] = {-1, 0, +1, +1, 0, -1};

bool legal(int r, int c)
{
    if (r >= 0 && c >= 0 && (maps[r][c] == '@' || maps[r][c] == 'D' ))
        return 1;
    return 0;
}
int bfs(int start, int end)
{
	while(q.size()) q.pop();
	q.push(start*1000+end);
	memset(vis, 0, sizeof(vis));
	vis[start][end] = 1;
	while (!q.empty())
		{
			int u = q.front();
			int r = u / 1000;
			int c = u % 1000;
			for (int i = 0; i < 6; i++)
				{
					int rr = r + dx[i];
					int cc = c + dy[i];
					if (legal(rr, cc) && (vis[rr][cc] == 0))
						{
							// fprintf(stderr, "%d %d   %c\n",r, c, maps[rr][cc]);
							q.push(rr * 1000 + cc);
							if (maps[rr][cc] == 'D') return vis[r][c];
							vis[rr][cc] = vis[r][c] + 1;
						}
				}
			q.pop();
		}
	return inf;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int i, j, kase = 0;
	while (scanf("%d %d\n", &h, &t) == 2)
		{
			kase++;
			memset(maps, 0, sizeof(maps));
			int sc, sr;
			int res;
			int times = 0;
			// int ans = 1000;
			sc = sr = 0;
		// 	for (i = 0; i < h; i++) {
		// 		gets(maps[i]);
		// 		int l = strlen(maps[i]), nl = 0, nz = 0;
		// 		for (int j = 0; j < l; ++j)
		// 			if (maps[i][j] != ' ') tmp[nl++] = maps[i][j];
		// 		for (int j = 1; j < h-i; ++j) maps[i][nz++] = ' ';
		// 		for (int j = 0; j < nl; ++j) maps[i][nz++] = tmp[j], maps[i][nz++] = ' ';
		// 		maps[i][--nz] = 0;
		// 		// puts(maps[i]);
		// 	}
		// 	int flag = 1;
		// 	for (i = 0; i < h; i++)
		// 		for (j = 0; j < 2 * h + 1; j++)
		// 				if (maps[i][j] == 'S')
		// 					{
		// 						sr = i;
		// 						sc = j;
		// 						flag = 0;
		// 						goto gt;
		// 					}
		// gt:;
		// 	if (!flag)
		// 		ans = bfs(sr * 1000 + sc, ending[i]);
		for (int i = 0, j, k, l; i < h; ++i) {
			gets(maps[i]);
			for (j = 0, k = 0, l = strlen(maps[i]); j < l; ++j)
				if (!pd(maps[i][j])) maps[i][k++] = maps[i][j];
			for (j = k; j < l; ++j) maps[i][j] = 0;
		}
		
		int ans = inf;
		for (int i = 0; i <= h; ++i)
			for (int j = 0, l = strlen(maps[i]); j < l; ++j)
				if (maps[i][j] == 'S') ans = bfs(i, j);
		
		if (kase > 1) puts("");
		printf("Maze #%d :\n", kase);
		if (ans <= t)
			{
				t = ans;
				if (t == 1)
					printf("Hurry up, You need 1 minute to escape!\n");
				else
					printf("Hurry up, You need %d minutes to escape!\n", t);
			}
		else
			printf("Oh No, I'm afraid that you don't have enough time to escape!\n");
		}
	return 0;
}
