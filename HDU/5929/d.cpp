#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
const int maxn = 2*1e5;
#define met(a,b) memset(a,b,sizeof(a))
char s[4][10]={"PUSH","POP","REVERSE","QUERY"};
ll num[2*maxn];
int main()
{
    int t;
    ll k=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case #%lld:\n",k++);
        ll len=0;
        ll flag=1;
        ll num1=-inf,num2=inf;
        ll l=maxn,r=maxn-1;
        for(ll i=0;i<n;i++)
        {
            char s1[10];
            scanf("%s",s1);
            if(strcmp(s[0],s1)==0)
            {
                ll x,pos;
                scanf("%lld",&x);
                if(flag)
                {
                    num[++r]=x;
                    pos=r;
                }
                else
                {
                    num[--l]=x;
                    pos=l;
                }
                len++;
                if(x==0)
                {
                    num1=max(num1,pos);
                    num2=min(num2,pos);
                }
            }
            if(strcmp(s[1],s1)==0)
            {
                if(flag)
                    r--;
                else
                    l++;
                len--;
            }
            if(strcmp(s[2],s1)==0)
            {
                flag^=1;
            }
            if(strcmp(s[3],s1)==0)
            {
                if(len<=0)
                {
                    printf("Invalid.\n");
                    continue;
                }
                else
                {
                    if(num1==-inf&&num2==inf)
                    {
                        ll len=r-l+1;
                        if(len&1)
                            printf("1\n");
                        else
                            printf("0\n");
                        continue;
                    }
                    if(flag)
                    {
                        ll ling=min(num1,num2);
                        ll len=ling-l+1;
                        if(ling==r)
                            len--;
                        if(len&1)
                           printf("1\n");
                        else
                            printf("0\n");
                    }
                    else
                    {
                        ll ling=max(num1,num2);
                        ll len=r-ling+1;
                        if(ling==l)
                            len--;
                        if(len&1)
                            printf("1\n");
                        else
                            printf("0\n");
                    }
                }
            }
        }
    }
}