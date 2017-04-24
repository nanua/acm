#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int T, n, m;
char str[110][110];
int  cnt[110][110];

int main() {
#ifndef ONLINE_JUDGE
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
#endif
        for (scanf("%d",&T); T; T--) {
                scanf("%d %d\n", &n, &m);
                memset(str, 0, sizeof(str));
                memset(cnt, 0, sizeof(cnt));
                for (int i = 1; i <= n; ++i) scanf("%s",str[i]+1);

                int maxans = 0;
                for (int i = 0; i <= n+1; ++i)
			    for (int j = 0; j <= m+1; ++j)
				    if (str[i][j] != '#')
                                for (int k = 0; k <= 3; ++k) {
                                        int ni = i + dx[k], nj = j + dy[k];
                                        if (0 <= ni && ni <= n+1 && 0 <= nj && nj <= m+1) {
                                                cnt[i][j] += (str[ni][nj] == '#');
                                                maxans = max(maxans, cnt[i][j]);
                                        }                                   
                                }

                int ans = 0;
                for (int i = 0; i <= n+1; ++i)
                        for (int j = 0; j <= m+1; ++j)
                                if (str[i][j] != '#' && cnt[i][j] == maxans) ans++;
                printf("%d\n", ans);       
        }
}
