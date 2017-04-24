/** 
hdu5380 贪心+双端队列 
题目大意：一个人从0走到n知道ai为i节点到0的距离，没行走单位距离要消耗一颗糖，在所有节点中可以进行买糖和卖糖价格为sell[i]和buy[i],问走到n节点话费最小为多少 
解题思路：从0开始，每次都把当前携带的糖的数量为C，到下一个节点，如果卖的价格高的话就把当前口袋里剩的价钱较低买的换成当前点卖的价格（因为当前剩的糖是多余的 
           走到最后是要被退掉的，所以我们此举把退的价格抬高了），然后把前一个节点到当前节点路上消耗的糖在现在买回来，保持携带糖为C，走到n后把所有剩的糖退掉 
           思想有点难理解，需要好好想一想，贴上标程 
*/  
#include <iostream>  
#include <cstdio>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
typedef long long LL;  
const int MAXN=200000+1000;  
struct que  
{  
    int val,cnt;  
} Q[MAXN*2];  
int l,r,tot;  
LL ans;  
void Max(int v)  
{  
    int num=0;  
    while(l<=r&&Q[l].val<v)  
    {  
        num+=Q[l].cnt;  
        l++;  
    }  
    if(num)  
    {  
        --l;  
        Q[l].cnt=num;  
        Q[l].val=v;  
    }  
}  
void Min(int v)  
{  
    while(l<=r&&Q[r].val>v)  
    {  
        ans-=1LL*Q[r].val*Q[r].cnt;  
        tot+=Q[r].cnt;  
        --r;  
    }  
}  
void Del(int v)  
{  
    while(v)  
    {  
        int t=min(Q[l].cnt,v);  
        Q[l].cnt-=t;  
        v-=t;  
        if(Q[l].cnt==0)++l;  
    }  
}  
int A[MAXN],n,c,sell[MAXN],buy[MAXN];  
int main()  
{  
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&c);  
        A[0]=0;  
        for(int i=1; i<=n; i++)scanf("%d",&A[i]);  
        for(int i=0; i<=n; i++)scanf("%d%d",&buy[i],&sell[i]);  
        l=r=n;  
        --r;  
        ans=0;  
        for(int i=0; i<n; i++)  
        {  
            //将买入价小于卖出价的合并  
            Max(sell[i]);  
            //补充使得满油  
            tot=(i==0)?c:A[i]-A[i-1];  
            //将买入价大于当前买入价的油都退了，更新答案并计算需要补充的油tot  
            Min(buy[i]);  
            //将买入的油数量和单价入队列  
            Q[++r].val=buy[i];  
            Q[r].cnt=tot;  
            ans+=1LL*buy[i]*tot;  
            //消化从i...i+1这个点的油（最便宜的  
            Del(A[i+1]-A[i]);  
        }  
        //更新最后一个点  
        Max(sell[n]);  
        //把多余的油退掉  
        for(int i=l; i<=r; i++)ans-=1LL*Q[i].val*Q[i].cnt;  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  
