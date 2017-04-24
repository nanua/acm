/*
    hdu 2444
    题意：判断是否是二分图，并输出最大匹配数
 
    YY：用'临点填色法'判断，相邻点异色，发现同色则不成立
        然后匈牙利算法， 求出个数除2
 
    注：匈牙利算法时间复杂度 '邻接表': O(mn)，邻接矩阵: O(n^3)
*/
 
 
#include <stdio.h>
#include <string.h>
 
bool map[210][210];//连接图
bool visit[210];//判断是否访问过
int link[210];// 当前链接表
int judge[210];// 判断二分图时 0-1表
 
int queue[210];
int n,m;
 
bool BFS()
{ //二分图BFS判断
    int v,start = 0,end = 1;
    queue[0] = 1; 
    for(int i=0;i<=n;i++) 
        judge[i] = -1;
    v = queue[start];
    judge[1] = 0;
    memset(visit,0,sizeof(visit));
 
    while(start<end)
    {
        v= queue[start];
        for(int i = 1;i <= n; i++)
        {
            if(map[v][i]){
                if(judge[i] == -1){
                    judge[i] = (judge[v]+1)%2;
                    queue[end++] = i;   
                }
                else{
                    if(judge[i] == judge[v])
                        return false;           
                }
            }
        }
        start++;
    }
    return true;
}
 
int can(int r)
{
    for(int i=1;i<=n;i++)
    {
        if(map[r][i] && visit[i] == 0){
            visit[i] = 1;
            if(link[i]==0 || can(link[i])){
                link[i] = r;
                return 1;
            }
        }
    }
    return 0;
}
 
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
            map[b][a] = 1;
        }
 
        //judge the bipartite graph
 
        if(!BFS()) {
            printf("No\n");continue;
        }
 
        //the maximum number of pair
        int num = 0;
        memset(link,0,sizeof(link));
        for(int i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));          
            if(can(i)) num++;
        }
        printf("%d\n",num/2);
    }
    return 0;
}
