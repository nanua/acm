#include<cstdio>
#include<cstring>
#define bid(x) {if (x>=N-1) x=1;}
const int N=202*505;
struct qq
{
	int s,c[128],fail;
}t[N];
int len=0;
char str[10005];
int n;
bool ans[505];
int ans1;
inline void init (int x)
{
	t[x].s=t[x].fail=0;
	memset(t[x].c,-1,sizeof(t[x].c));
}
inline void bt (int root,int x1)
{
	int x=root,len1=strlen(str);
	for (int u=0;u<len1;u++)
		{
			int y=str[u]-' ';
			if (t[x].c[y]==-1)
				{
					len++;
					init(len);
					t[x].c[y]=len;
				}
			x=t[x].c[y];
		}
	t[x].s=x1;
	return ;
}
int q[N*5];//队列
int st,ed; 
inline void bfs ()
{
	st=1;ed=2;
	q[st]=0;
	while (st!=ed)
		{
			int x=q[st];
			for (int u=0;u<128;u++)
				{
					int son=t[x].c[u],f=t[x].fail;
					if (son>=0)
						{
							if (x==0)t[son].fail=0;
							else t[son].fail=t[f].c[u];
							q[ed]=son;
							ed++;
							bid(ed);
						}
					else
						if (x==0) t[x].c[u]=0;
						else t[x].c[u]=t[f].c[u];
				}
			st++;
			bid(st);
		}
}
inline void solve ()
{
	int x=0,len1=strlen(str);
	for (int u=0;u<len1;u++)
		{
			if (ans1>=3) return ;
			int y=str[u]-' ';
			x=t[x].c[y];
			int j=x;
			while (t[j].s!=0)
				{
					if (ans[t[j].s]==false)
						{
							ans[t[j].s]=true;
							ans1++;
							if (ans1>=3) break;
						}
					j=t[j].fail;
				}
			j=t[j].fail;
			if (t[j].s!=0&&ans[t[j].s]==false)
				{
					ans[t[j].s]=true;
					ans1++;
				}
		}
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	while (scanf("%d",&n)!=EOF)
		{
			len=0;
			init(0);
			for (int u=1;u<=n;u++)
				{
					scanf("%s",str);
					bt(0,u);
				}
			bfs();
			int m;
			scanf("%d",&m);
			int ooo=0;
			for (int u=1;u<=m;u++)
				{
					memset(ans,false,sizeof(ans));
					ans1=0;
					scanf("%s",str);
					solve();
					if (ans1!=0)
						{
							printf("web %d:",u);
							int ans2=0;
							for (int i=1;i<=n;i++) 
								{
									if (ans[i]==true)
										{
											printf(" %d",i);
											ans2++;
											if (ans2>=ans1) break;
										}
								}
							ooo++;
							printf("\n");
						}
				}
			printf("total: %d\n",ooo);
		}
	return 0;
}
