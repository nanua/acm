#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct data{int l,r,v,s,rnd,w;}tr[100001];
int n,size,root,ans;
void update(int k)
{tr[k].s=tr[tr[k].l].s+tr[tr[k].r].s+tr[k].w;}
void rturn(int &k)
{int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;tr[t].s=tr[k].s;update(k);k=t;}
void lturn(int &k)
{int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;tr[t].s=tr[k].s;update(k);k=t;}
void insert(int &k,int x)
{
	if(k==0){size++;k=size;tr[k].s=tr[k].w=1;tr[k].v=x;tr[k].rnd=rand();return;}
	tr[k].s++;
    if(tr[k].v==x)tr[k].w++;
	else if(x>tr[k].v)
	{insert(tr[k].r,x);if(tr[tr[k].r].rnd<tr[k].rnd)lturn(k);}
	else 
	{insert(tr[k].l,x);if(tr[tr[k].l].rnd<tr[k].rnd)rturn(k);} 
}
void del(int &k,int x)
{
    if(k==0)return; 
	if(tr[k].v==x)
	{
		if(tr[k].w>1){tr[k].w--;tr[k].s--;return;}
		if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
		else if(tr[tr[k].l].rnd<tr[tr[k].r].rnd){rturn(k);del(k,x);}
		else {lturn(k);del(k,x);}
	}
	else if(x>tr[k].v){tr[k].s--;del(tr[k].r,x);}
	else {tr[k].s--;del(tr[k].l,x);}
}
int ask_rank(int k,int x)
{
    if(k==0)return 0;
	if(tr[k].v==x)return tr[tr[k].l].s+1;
	else if(x>tr[k].v)return tr[tr[k].l].s+tr[k].w+ask_rank(tr[k].r,x);
	else return ask_rank(tr[k].l,x);
}
int ask_num(int k,int x)
{
    if(k==0)return 0;
	if(x<=tr[tr[k].l].s)return ask_num(tr[k].l,x);
    else if(x>tr[tr[k].l].s+tr[k].w)return ask_num(tr[k].r,x-tr[tr[k].l].s-tr[k].w);
    else return tr[k].v;
}
void ask_before(int k,int x)
{
    if(k==0)return;
    if(tr[k].v<x){ans=k;ask_before(tr[k].r,x);}
    else ask_before(tr[k].l,x);
}
void ask_after(int k,int x)
{
   if(k==0)return;
   if(tr[k].v>x){ans=k;ask_after(tr[k].l,x);}
   else ask_after(tr[k].r,x);
}
int main()
{
	freopen("ptphs.in","r",stdin);
	freopen("cmp.out","w",stdout);
	scanf("%d",&n);
	int f,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&f,&x);
		if (f > 2) cout << f << " ";
		switch(f)
		{
			case 1:insert(root,x);break;
			case 2:del(root,x);break;
			case 3:printf("%d\n",ask_rank(root,x));break;
			case 4:printf("%d\n",ask_num(root,x));break;
			case 5:ans=0;ask_before(root,x);printf("%d\n",tr[ans].v);break;
			case 6:ans=0;ask_after(root,x);printf("%d\n",tr[ans].v);break;
		}
	}
	return 0;
} 
