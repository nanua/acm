#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<time.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000");

using namespace std;

#define INF 0x3f3f3f3f
#define maxn 2000002
#define mod (1000000007)
#define inv 500000004
#define Mod(x) x=(((x)+mod)%mod)

char Ma[maxn*2];
int Mp[maxn*2];
void Manacher(char s[],int len)
{
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0; i<len; i++)
		{
			Ma[l++]=s[i];
			Ma[l++]='#';
		}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0; i<l; i++)
		{
			Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
			while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
			if(i+Mp[i]>mx)
				{
					mx=i+Mp[i];
					id=i;
				}
		}
}

int len;
char s[maxn];
long long L[maxn],R[maxn];
long long Lc[2][maxn],Rc[2][maxn];

void init()
{
	memset(Lc,0,sizeof Lc);
	memset(Rc,0,sizeof Rc);

}

void update1(int mid,int r,int val)
{
	Lc[0][mid]+=val;
	Lc[0][mid+r+2]-=val;
	Lc[1][mid]+=1;
	Lc[1][mid+r+2]-=1;
	Rc[0][mid-r-2]-=val;
	Rc[0][mid]+=val;
	Rc[1][mid-r-2]-=1;
	Rc[1][mid]+=1;
}

void solveOdd()
{
	long long sum=0,k=0;
	for(int i=2; i<=2*len; i+=2)
		{
			sum+=2ll*Lc[0][i];Mod(sum);
			k+=Lc[1][i];Mod(k);
			L[i]=(sum-k*(i/2)+mod)%mod;
			Mod(L[i]);
		}
	sum=0,k=0;
	for(int i=2*len; i>=2; i-=2)
		{
			sum+=2ll*Rc[0][i];Mod(sum);
			k+=Rc[1][i];Mod(k);
			R[i]=((sum-k*(i/2))+mod)%mod;
			Mod(R[i]);
		}
}

void update2(int mid,int r,int val)
{
	Lc[0][mid]+=val;
	Lc[0][mid+r]-=val;
	Lc[1][mid]+=1;
	Lc[1][mid+r]-=1;
	Rc[0][mid-r]-=val;
	Rc[0][mid]+=val;
	Rc[1][mid-r]-=1;
	Rc[1][mid]+=1;
}

void solveEven()
{
	long long sum=0,k=0;
	for(int i=2; i<=2*len; i++)
		{
			sum+=2ll*Lc[0][i];Mod(sum);
			k+=Lc[1][i];Mod(k);
			L[i]+=((((sum-k*i)+mod)%mod)*inv)%mod;
			Mod(L[i]);
		}
	sum=0,k=0;
	for(int i=2*len; i>=2; i--)
		{
			sum+=2ll*Rc[0][i];Mod(sum);
			k+=Rc[1][i];Mod(k);
			R[i]+=((((sum-k*i)+mod)%mod)*inv)%mod;
			Mod(R[i]);
		}

}

int main()
{
	
	freopen("a.in","r",stdin);
	freopen("cmp.out","w",stdout);
	while(scanf("%s",s)!=EOF)
		{
			memset(L,0,sizeof L);
			memset(R,0,sizeof R);
			len=strlen(s);
			Manacher(s,len);
			init();
			for(int i=2; i<=2*len; i+=2)
				{
					int r=(Mp[i]/2-1)*2;
					update1(i,r,i/2);
				}
			solveOdd();
			init();
			for(int i=3; i<=2*len-1; i+=2)
				{
					int r=Mp[i]-1;
					update2(i,r,i);
				}
			solveEven();
			long long ans=0;
			for(int i=2; i<len*2; i+=2)
				{
					ans+=(L[i]*R[i+2])%mod;
					Mod(ans);
				}
			printf("%lld\n",ans);
		}
	return 0;
}
