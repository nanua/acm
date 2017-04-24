#include<iostream>

using namespace std;

int p[10];
long long map[2][10];
int n,a,b;//人的编号从1开始 

int getindex(int a)//返回第n个人身上数字 
{
	int i=1;
	while(a-p[i]>0) a-=p[i++];
	return i;
}

int getmap(int a,int b)
{
	if(b<0) return map[a][b+9];
	if(b==0) return map[a][0]+map[a][9];
	return map[a][b];
}

//F(peopleindex,sum%9)
//F(m,n)=F(m-1,n)+F(m-1,(n-i)%9)
long long dp(int a,int b)
{
	int i,j;
	for(i=0;i<2;i++)//init 
		{
			map[i][0]=1;
			for(j=1;j<10;j++)
				{
					map[i][j]=0;
				}
		}
	map[getindex(1)%2][getindex(1)]=1;//递推初值 
	for(i=getindex(1)+1;i<=a;i++)//从第二个人开始递推 
		{
			for(j=1;j<=9;j++)
				{
					map[i%2][j]=(getmap((i-1)%2,j)+getmap((i-1)%2,j-getindex(i)))%258280327;
					//cout<<getmap((i-1)%2,j)<<"+"<<getmap((i-1)%2,(j-getindex(i)>0)?(j-getindex(i)):(j-getindex(i)+9))<<endl;
					//cout<<getindex(1)<<endl<<"9:"<<getindex(i)<<endl;
					//cout<<"map["<<i<<"]["<<j<<"]="<<map[i%2][j];
				}
			//cout<<endl;
		}
	/*for(i=0;i<=1;i++)
	  {
	  for(j=1;j<=b;j++)
	  {
	  cout<<"map["<<i<<"]["<<j<<"]="<<map[i][j];
	  }
	  cout<<endl;
	  }*/
	return map[a%2][b];
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	int t,i,j,tmp;
	long long sum,m;
	cin>>t;
	while(t-->0)
		{
			for(i=1;i<=9;i++) p[i]=0;
			m=0;
			scanf("%d%d%d",&n,&a,&b);
			sum=0;
			for(i=0;i<n;i++)
				{
					scanf("%d",&tmp);
					p[tmp]++;
					sum+=tmp;
				}
			sum%=9;
			if(a%9==sum) m++;//所有人进同一扇门 
			if(b%9==sum) m++;
			if(sum!=(a+b)%9)
				{
					printf("%lld\n",m);
					continue;
				}
			m+=dp(n,a);
			printf("%lld\n",m);
		}
	return 0;
}
