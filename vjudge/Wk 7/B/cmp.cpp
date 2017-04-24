#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=100005;
int num1[maxn];
int num2[maxn];
int main()
{

	freopen("a.in","r",stdin);
	freopen("c.out","w",stdout);
	int N;
	while(~scanf("%d",&N)) {
		for(int i=0; i<N; i++)
			scanf("%d",&num1[i]);
		int temp=1;//进制
		long long int sum=0;//记录进位总数
		for(int i=0; i<9; i++) { //九位数
			temp=temp*10;
			for(int j=0; j<N; j++)
				num2[j]=num1[j]%temp;
			sort(num2,num2+N);//升序排列
			int flag=N;//临时记录N
			for(int j=0; j<N; j++) {
				while(flag&&num2[j]+num2[flag-1]>=temp)//找到进位的边界
					flag--;
				flag<=j?sum+=(N-flag-1):sum+=(N-flag);
			}
		}
		printf("%lld\n",sum/2);
	}
	return 0;
}
