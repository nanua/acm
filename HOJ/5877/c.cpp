#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define N 100010
#define M 100010
#define Mod 1000000007
#define LL long long
#define INF 0x7fffffff
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;i++)
#define For(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
#define REP(i,f_end,f_start) for(int i=f_end;i>=f_start;i--)
#define Rep(i,f_end,f_start) for(int i=f_end;i>f_start;i--)
#define MT(x,i) memset(x,i,sizeof(x))
#define gcd(x,y) __gcd(x,y)
const double PI = acos(-1);

int c[N<<1];
int Lowbit(int x)
{
	return x&(-x);
}
int getsum(int pos)
{
	int sum=0;
	while(pos>0)
		{
			sum+=c[pos];
			pos-=Lowbit(pos);
		}
	return sum;
}
void update(int pos,int num,int n)
{
	while(pos<=n)
		{
			c[pos]+=num;
			pos+=Lowbit(pos);
		}
}

int n;
LL sum,k;
LL w[N<<1];
vector<int> v[N];
int p[N<<1];
int xin;
void dfs(int rt)
{
	int pos;
	pos=w[rt+n];
	sum += getsum(pos);

	update(w[rt],1,xin);
	For(i,0,v[rt].size()){
		int son = v[rt][i];
		dfs(son);
	}
	update(w[rt],-1,xin);
}

bool cmp(int x,int y)
{
	return w[x]<w[y];
}

bool f[N];
int main()
{
	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
	int t,x,y;
	scanf("%d",&t);
	while(t--)
		{
			scanf("%d%lld",&n,&k);
			FOR(i,1,n){
				scanf("%lld",&w[i]);
				if(w[i]==0) w[n+i]=INF;
				else w[n+i]=k/w[i];
				p[i]=i;
				p[n+i]=n+i;
			}
			sort(p+1,p+n+n+1,cmp);
			xin = 0;
			int pre = -1;
			FOR(i,1,n+n)
				{
					if(w[p[i]]>pre){ pre=w[p[i]]; w[p[i]]=++xin; }
					else{ pre=w[p[i]]; w[p[i]]=xin; }
				}
			memset(f,0,sizeof(f));
			For(i,1,n){
				scanf("%d%d",&x,&y);
				v[x].push_back(y);
				f[y]=1;
			}
			MT(c,0);
			sum = 0;
			FOR(i,1,n){
				if(f[i]==false)
					{
						dfs(i);
						break;
					}
			}
			printf("%lld\n",sum);
			FOR(i,1,n){
				v[i].clear();
			}
		}
	return 0;
}
