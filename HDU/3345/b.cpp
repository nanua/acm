#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int vis[10005];
int ehome[10005];
char map[105][105];
int queue[10005];
int head,tail;
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
void init()
{
	head=tail;
}
void push(int x)
{
	queue[tail++]=x;
}
void pop()
{
	head++;
}
int get_front()
{
	return queue[head];
}
int empty()
{
	return head==tail;
}
void bfs(int start,int n,int m,int mv)
{
	int lgd,x,y,i,x1,y1;
	memset(vis,0,sizeof(vis));
	memset(ehome,0,sizeof(ehome));
	init();
	vis[start]=1;
	ehome[start]=mv;
	push(start);
	while(empty()==0)
		{
			lgd=get_front();
			x=lgd/100;
			y=lgd%100;
			pop();
			for(i=0; i<4; i++)
				{
					x1=x+dx[i];
					y1=y+dy[i];
					if(x1>=0&&x1<n&&y1>=0&&y1<m)
						{
							if(map[x1][y1]=='E'&&lgd!=start) ehome[lgd]=0;
						}
				}
			for(i=0; i<4; i++)
				{
					x1=x+dx[i];
					y1=y+dy[i];
					if(x1>=0&&x1<n&&y1>=0&&y1<m)
						{
							if(vis[x1*100+y1]==1||map[x1][y1]=='#'||map[x1][y1]=='E') continue;
							if(map[x1][y1]=='.'&&ehome[lgd]>=1)
								{
									vis[x1*100+y1]=1;
									push(x1*100+y1);
									ehome[x1*100+y1]=ehome[lgd]-1;
									map[x1][y1]='*';
								}
							else if(map[x1][y1]=='T'&&ehome[lgd]>=2)
								{
									vis[x1*100+y1]=1;
									push(x1*100+y1);
									ehome[x1*100+y1]=ehome[lgd]-2;
									map[x1][y1]='*';
								}
							else if(map[x1][y1]=='R'&&ehome[lgd]>=3)
								{
									vis[x1*100+y1]=1;
									push(x1*100+y1);
									ehome[x1*100+y1]=ehome[lgd]-3;
									map[x1][y1]='*';
								}
							else if(map[x1][y1]=='P'&&ehome[lgd]>=2)
								{
									push(x1*100+y1);
									vis[x1*100+y1]=1;
									ehome[x1*100+y1]=ehome[lgd]-1;
								}
						}
				}
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int t,i,n,m,mv,j,k,start;
	scanf("%d",&t);
	for(i=0; i<t; i++)
		{
			if(i>=1) puts("");
			scanf("%d %d %d",&n,&m,&mv);
			for(j=0; j<n; j++)
				{
					scanf("%s",map[j]);
					for(k=0; k<m; k++)
						{
							if(map[j][k]=='Y') start=j*100+k;
						}
				}
			bfs(start,n,m,mv);
			for(j=0; j<n; j++)
				{
					puts(map[j]);
				}
		}
	return 0;
}
