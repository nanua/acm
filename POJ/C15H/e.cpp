#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 1000010
using namespace std;
typedef long long ll;
template <class T>
inline bool read(T &res){
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0;   //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    res=(c=='-')?0:(c-'0');
     while(c=getchar(),c>='0'&&c<='9') res=res*10+(c-'0');
     res*=sgn;
    return res;
}
///////
int n,k,a,b;
int ans[maxn];
int p[maxn];
int que1[maxn],que2[maxn],que3[maxn];
int main()
{

	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
    read(n);read(k);read(a);read(b);
    for(int i=1;i<=n;i++) read(p[i]);
    int h1=1,t1=1;
    for(int i=1;i<=n;i++){
        while(h1<t1&&p[que1[t1-1]]<=p[i]) t1--;
        que1[t1++]=i;
        while(h1<t1&&que1[h1]<i-k+1) h1++;
        if(i>=k&&h1<t1) ans[que1[h1]]+=a;
    }
    int h2=1,t2=1,h3=1,t3=1;
    for(int i=n;i;i--){
        int tmp=que2[h2];
        while(h2<t2&&p[que2[t2-1]]>=p[i]) t2--;
        que2[t2++]=i;
        while(h2<t2&&que2[h2]-i>k-1) h2++;
        if(que2[h2]!=tmp){
            for(int j=tmp;j>que2[h2];j--){
                if(p[que2[h2]]==p[j]) continue;
                while(h3<t3&&p[que3[t3-1]]>=p[j]) t3--;
                que3[t3++]=j;
            }
        }
        while(h3<t3&&que3[h3]-i>k-1) h3++;
        int pos=0;
        if(h2+1<t2) pos=que2[h2+1];
        if(pos&&h3<t3) pos= p[que2[h2+1]] <= p[que3[h3]] ? que2[h2+1] : que3[h3];
        else if(h3<t3) {
            while(h2<t2&&h3<t3&&p[que3[h3]]==p[que2[h2]]) h3++;
            pos=que3[h3];
        }
        if(i<=n-k+1&&pos) ans[pos]+=b;
    }
    int cnt=0;int tot=n-k+1;double sum=0.0;
y    for(int i=1;i<=n;i++){
        if(ans[i]){
            cnt++;
            sum+=(double)ans[i]/(double)tot;
        }
    }
    sum/=(1.0*cnt);
    double sum2=0.0;
    for(int i=1;i<=n;i++){
        if(ans[i])
            sum2+=(sum-1.0*ans[i]/(1.0*tot))*(sum-1.0*ans[i]/(1.0*tot));
    }
    sum2/=(1.0*cnt);
    printf("%d %.4f\n",cnt,sum2);
}
