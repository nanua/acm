#include <cstdio>
#include <cstdlib>
#include <cstring>
int h, t, head, tail, countn;
int queue[50000];
int vis[410][420];
int ending[40010];
char maps[410][420], tmp[40010];
int dx[] = {0, 0, 1, 1, -1, -1};
int dy[] = {2, -2, 1, -1, 1, -1};

bool legal(int r, int c)
{
	if (maps[r][c] == '@' || maps[r][c] == 'D')
		return 1;
	return 0;
}

void init()
{
	head = tail = countn = 0;
}

void push(int x)
{
	countn++;
	queue[tail] = x;
	tail++;
}

void pop()
{
	head++;
	countn--;
}

int empty()
{
	return countn == 0 ;
}

int get_front()
{
	return queue[head];
}

int bfs(int start, int end)
{
	push(start);
	memset(vis, 0, sizeof(vis));
	vis[start / 1000][start % 1000] = 1;
	while (get_front() != end && empty() == 0)
		{
			int u = get_front();
			int r = u / 1000;
			int c = u % 1000;
			for (int i = 0; i < 6; i++)
				{
					int rr = r + dx[i];
					int cc = c + dy[i];
					if (legal(rr, cc) && (vis[rr][cc] == 0))
						{
							// fprintf(stderr, "%d %d   %c\n",r, c, maps[rr][cc]);
							push(rr * 1000 + cc);
							if (maps[rr][cc] == 'D') return vis[r][c];
							vis[rr][cc] = vis[r][c] + 1;
						}
				}
			pop();
		}
	if (empty() == 0)
		return vis[get_front() / 1000][get_front() % 1000] - 1;
	return 0x3f3f3f3f;
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
			int ans = 0x3f3f3f3f;
			sc = sr = 0;
			for (i = 0; i < h; i++) {
				gets(maps[i]);
				int l = strlen(maps[i]), nl = 0, nz = 0;
				for (int j = 0; j < l; ++j)
					if (maps[i][j] != ' ') tmp[nl++] = maps[i][j];
				for (int j = 1; j < h-i; ++j) maps[i][nz++] = ' ';
				for (int j = 0; j < nl; ++j) maps[i][nz++] = tmp[j], maps[i][nz++] = ' ';
				maps[i][--nz] = 0;
				// puts(maps[i]);
			}
			int flag = 1;
			for (i = 0; i < h; i++)
				for (j = 0; j < 2 * h + 1; j++)
						if (maps[i][j] == 'S')
							{
								sr = i;
								sc = j;
								flag = 0;
								goto gt;
							}
		gt:;
			if (!flag)
				init(), ans = bfs(sr * 1000 + sc, ending[i]);
			
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
