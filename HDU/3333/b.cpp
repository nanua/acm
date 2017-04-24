#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
using namespace std;

#define INF 0x3f3f3f3f
#define eps 0.000001
#define lowbit(x)  x&(-x)
#define mt(a,b) memset(a,b,sizeof(a))

#ifdef __int64  LL
typedef __int64 LL;
#else
typedef long long LL;
#endif // __int64


/**
题目可以用树状数组or线段树解,比较难想的是如何处理相同的数.看了题解才明白怎么写
树状数组+离线处理+离散化
查询序列按右端点从小到大排序，然后便利查询序列
离散化是为了检查当前的a[i]是否已经被插入了(vis数组),
Case 1: 如没有正常插入树状数组中
Case 2: 如果已经插入了,需要将其删除，设插入的位置为i，则从c[i]到c[n]所有包含a[i]的节点(i+=lowbit(i))都要加上"-a[i]"
因此需要一个last[]数组,记录第i个点插入的位置
所以在Case 1中要记录last[a[i]离散化后的值]
之后再插入树状数组中(代码和Case 1一样)

插入序列排序的目的: 之前的插入会删除重复数据再加入到 “ 后面的位置 ”，
那么再插入时可能会出现要将 “ 后面的位置 ”的数据再重新插回原来位置
插入序列排序的目的就是保证上述情况不会出现

插入的第二个循环是for(int j=q[i-1].r+1;j<=R;j++)
这样做是一种优化，否则TLE
但是对于这样的样例
1
5
5 1 2 1 3
2
2 3
1 4
会出现一个问题:访问1 4时，并没有更新到a[1]...
但是代码还是A了...why？
原因是:当访问第一组查询时，for循环中q[i-1].r+1中i-1=0,而q[0]没有进行过任何操作，是系统的默认初始值，也就是说q[i-1].r=0
所以再加‘ 1 ’后,for循环是从j=1开始执行的,相当于第一组询问时a[1],a[2],....,a[q[1].r]都被加入到树状数组中了，这样解决了这个问题

插入数据处理结束

求和只需要像正常求区间和一样就可以
*/

const int maxn = 30000+100;
struct Num{
    LL v;
    int index;
    int lsh;
}a[maxn];

struct que{
    int l,r;
    int index;
    LL ans;
}q[100100];

int vis[maxn];
LL c[maxn];
int last[maxn];
int n;

int cmp1(Num a,Num b){
    return a.v<b.v;
}

int cmp2(Num a,Num b){
    return a.index<b.index;
}

int cmp3(que a,que b){
    if(a.r==b.r)   return a.l<b.l;
    return a.r<b.r;
}

int cmp4(que a,que b){
    return a.index<b.index;
}

void lshhh(){
    sort(a+1,a+1+n,cmp1);

    int k=0;
    a[1].lsh=k++;

    for(int i=2;i<=n;i++){
        if(a[i].v==a[i-1].v)  a[i].lsh=k-1;
        else a[i].lsh=k++;
    }

    sort(a+1,a+1+n,cmp2);
}

void update(LL val,int pos){
    while(pos<=n){
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}

LL getsum(int pos){
    LL s=0;

    while(pos>0){
        s+=c[pos];
        pos-=lowbit(pos);
    }

    return s;
}

int main(){
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    int cas;
    scanf("%d",&cas);

    while(cas--){
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].v);

            a[i].index=i;
        }

        lshhh();

        int t;
        scanf("%d",&t);

        for(int i=1;i<=t;i++){
            scanf("%d%d",&q[i].l,&q[i].r);

            q[i].index=i;
        }

        sort(q+1,q+1+t,cmp3);

        mt(vis,0);mt(c,0);mt(last,0);

        for(int i=1;i<=t;i++){
            int L=q[i].l;
            int R=q[i].r;

            for(int j=q[i-1].r+1;j<=R;j++){
                LL x=a[j].v;
                int is=a[j].lsh;

                if(vis[is]==1){
                    vis[is]=0;
                    update(-x,last[is]);
                }
                if(vis[is]==0){
                    last[is]=j;
                    vis[is]=1;
                    update(x,j);
                }
            }



            q[i].ans=getsum(R)-getsum(L-1);
        }

        sort(q+1,q+1+t,cmp4);

        for(int i=1;i<=t;i++)    printf("%lld\n",q[i].ans);
    }

    return 0;
}
/**
2
3
1 1 4
2
1 2
2 3
5
1 1 2 1 3
3
1 5
2 4
3 5
*/
