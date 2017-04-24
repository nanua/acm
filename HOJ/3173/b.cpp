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

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	for (scanf("%d", &T); T; T--) {
		scanf("%d %d\n", &n, &m);
		memset(str, 0, sizeof(str));
		for (int i = 2; i <= n+1; ++i) scanf("%s",str[i]+2);

		int maxans = 0, ans = 0;
		for (int i = 1; i <= n+2; ++i)
			for (int j = 1, cnt; j <= m+2; ++j)
				if (str[i][j] != '#'){
					cnt = 0;
					for (int k = 0; k <= 3; ++k)
						cnt += (str[i+dx[k]][j+dy[k]] == '#');
				
					if (cnt > maxans) maxans = cnt, ans = 1;
					else if (cnt == maxans) ans++;
				}
		printf("%d\n", ans);	   
	}		
}
