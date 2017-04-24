#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
int dis[600][600];
int u, v, w;
int inf = 0x3f3f3f3f;
int main()  
{  
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
    int n,m,c;  
    cin >> n >> m>> c;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int i = 1; i <= m; ++i)
	    cin >> u >> v >> w, dis[u][v] = dis[v][u] = min(dis[u][v], w);

    for (int k = 1; k <= n; ++k)
	    for (int i = 1; i <= n; ++i)
		    for (int j = 1; j <= n; ++j)
			    if (i != j && j != k && k != i)
			    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for (int i = 1; i <= c; ++i) {
	    cin >> u >> v;
	    if (dis[u][v] == inf) puts("Not connected");
	    else cout << dis[u][v] << endl;
    }
}  
