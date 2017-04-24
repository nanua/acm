#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")
#define ls i<<1
#define rs ls | 1
#define mid ((ll+rr)>>1)
#define pii pair<int,int>
#define MP make_pair

typedef long long LL;
const long long INF = 1e18+10;
const double Pi = acos(-1.0);
const int N = 1e5+10, M = 1e6+11, mod = 1e9+7, inf = 2e9;

LL K,ans,a[N];
int n,size,root,head[N],t;

struct data{
    int l,r,size,rnd,w;
    LL v;
}tr[N];
void update(int k)//更新结点信息
{
    tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;
}
void rturn(int &k)
{
    int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void lturn(int &k)
{
    int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void insert(int &k,LL x)
{
    if(k==0)
    {
        size++;k=size;
        tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].rnd=rand();
        return;
    }
    tr[k].size++;
    if(tr[k].v==x)tr[k].w++;
    else if(x>tr[k].v)
    {
        insert(tr[k].r,x);
        if(tr[tr[k].r].rnd<tr[k].rnd)lturn(k);
    }
    else
    {
        insert(tr[k].l,x);
        if(tr[tr[k].l].rnd<tr[k].rnd)rturn(k);
    }
}
void del(int &k,LL x)
{
    if(k==0)return;
    if(tr[k].v==x)
    {
        if(tr[k].w>1)
        {
            tr[k].w--;tr[k].size--;return;
        }
        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
        else if(tr[tr[k].l].rnd<tr[tr[k].r].rnd)
            rturn(k),del(k,x);
        else lturn(k),del(k,x);
    }
    else if(x>tr[k].v)
        tr[k].size--,del(tr[k].r,x);
    else tr[k].size--,del(tr[k].l,x);
}
int query_rank(int k,LL x)
{
    if(k==0)return 0;
    if(tr[k].v==x)return tr[tr[k].l].size+tr[k].w;
    else if(x>tr[k].v)
        return tr[tr[k].l].size+tr[k].w+query_rank(tr[k].r,x);
    else return query_rank(tr[k].l,x);
}



struct ss{int to,next;}e[N * 2];
void add(int u,int v) {e[t].next=head[u];e[t].to=v;head[u]=t++;}

void dfs(int u,int fa) {
        LL limit = INF;
        if(a[u] != 0) limit = K/(a[u]);
        ans += (query_rank(root,limit));
        insert(root,a[u]);
        for(int i = head[u]; i; i = e[i].next) {
            int to = e[i].to;
            if(to == fa) continue;
            dfs(to,u);
        }
        del(root,a[u]);
}
int d[N];
int main() {
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
        int T;
        scanf("%d",&T);
        while(T--) {
            size = 0;
            root = 0;
            memset(head,0,sizeof(head));t = 1;
            for(int i = 1; i < N; ++i) {
                tr[i].l = 0;
                tr[i].r = 0;
                d[i]  = 0;
            }
            scanf("%d%lld",&n,&K);
            for(int i = 1; i <= n; ++i) scanf("%lld",&a[i]);
            for(int i = 1; i < n; ++i) {
                int u,v;
                scanf("%d%d",&u,&v);
                add(u,v);add(v,u);
                d[v]++;
            }
            int rt;
            for(int i = 1; i <= n; ++i) if(!d[i]) rt = i;
            ans = 0;
            dfs(rt,0);
            printf("%lld\n",ans);

        }
        return 0;
}
