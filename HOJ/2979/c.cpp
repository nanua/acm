#include <cstdio>
#include <cstdlib>
#include <cstring>

int h, t, head, tail, countn;
int queue[6000];
int vis[110][220];
int ending[6000];
char maps[110][220];
int dx[] = {0, 0, 1, 1, -1, -1};
int dy[] = {2, -2, 1, -1, 1, -1};

bool legal(int r, int c)
{
    if ((maps[r][c] == '@' || maps[r][c] == 'D' ) && (r >= 0 && r <= h - 1 && c >= h - 1 - r && c <= h + r))
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
    queue[tail % 6000] = x;
    tail++;
}

void pop()
{
    head++;
    head %= 6000;
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
                push(rr * 1000 + cc);
                vis[rr][cc] = vis[r][c] + 1;
            }
        }
        pop();
    }
    if (empty() == 0)
        return vis[get_front() / 1000][get_front() % 1000] - 1;
    return 1000;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
    int i, j, kase = 0;
    while (scanf("%d%d", &h, &t) == 2)
    {
        kase++;
        memset(maps, 0, sizeof(maps));
        int sc, sr;
        int res;
        int times = 0;
        int ans = 1000;
        sc = sr = 0;
        getchar();
        for (i = 0; i < h; i++)
		  gets(maps[i]), puts(maps[i]);
        for (i = 0; i < h; i++)
            for (j = 0; j < 2 * h + 1; j++)
            {
                if (maps[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }
                if (maps[i][j] == 'D')
                {
                    ending[times] = i * 1000 + j;
                    times++;
                }
            }
        for (int i = 0; i < times; i++)
        {
            init();
            res = bfs(sr * 1000 + sc, ending[i]);
            ans = (ans < res) ? ans : res;
        }
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
        printf("\n");
    }
    return 0;
}
