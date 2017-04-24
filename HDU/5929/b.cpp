#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;
int a[600005];
int main(){
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
    int T;
    deque<int>d;
    char s[20];
    scanf("%d",&T);
    for(int xx=1;xx<=T;xx++){
        d.clear();
        int n,flag=1,x,l=300000-1,r=300000;
        scanf("%d",&n);
        printf("Case #%d:\n",xx);
        while(n--){
            scanf("%s",s);
            if(s[0]=='R') flag^=1;
            if(s[1]=='O'){
                if(flag){
                    r--;
                    if(a[r]==0) d.pop_back();
                }
                else{
                    l++;
                    if(a[l]==0) d.pop_front();
                }
            }
            if(s[2]=='S'){
                scanf("%d",&x);
                if(flag){
                    a[r]=x;
                    if(x==0) d.push_back(r);
                    r++;
                }
                else{
                    a[l]=x;
                    if(x==0) d.push_front(l);
                    l--;
                }
            }
            if(s[0]=='Q'){
                if(l==r-1) printf("Invalid.\n");
                else if(d.empty()) printf("%d\n",(r-l-1)%2);
                else{
                    int num=0;
                    if(!flag){
                        int y=d.back();
                        num+=(y!=l+1)+r-y-1;
                    }
                    else{
                        int y=d.front();
                        num+=(y!=r-1)+y-l-1;
                    }
                    printf("%d\n",num%2);
                }
            }
        }
    }
    return 0;
}
