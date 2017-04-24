#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <limits.h>
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-4)
#define inf (1<<28)
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ULL;
//用负数方便计算容斥的符号
int prime[19] = {-2, -3, -5, -7, -11, -13, -17, -19, -23, -29, -31, -37, -41, -43, -47, -53, -59, -61, -67};
vector <int> rongchi; //需要用容斥计算的幂值
//容斥原理
void get_rongchi(int r)
{
    rongchi.clear();
    for(int i = 0; abs(prime[i]) <= r; i++)//枚举幂值为质数的b//
    {
        int temp = rongchi.size();
        for(int j = 0; j < temp; j++)
        {
            if(abs(prime[i]*rongchi[j]) <= 63)
                rongchi.push_back(prime[i]*rongchi[j]);
        }
        rongchi.push_back(prime[i]);
    }
}
//计算1~x的范围内的数有多少存在于Y数列中
long long calculate(long long x)
{
    if(x == 1)
        return 0;
    long long ans = x;
    for(int i = 0; i < rongchi.size(); i++)
    {
        //若a^b=pow(a,b)=x则b=pow(x,1.0/a) ;
        //+0.5为了保证精度;-1是暂时不包含1（因为当a=1时，a^b一定会等于1）
        long long temp = (long long)(pow(x + 0.5, 1.0/abs(rongchi[i]))) - 1;
        //
        if(rongchi[i] < 0)
            ans -= temp;
        else
            ans += temp;
    }
    return ans - 1; //减去刚才没有包含在内的1
}
//迭代法求Y数列的第n个数
bool cmp(int x, int y) {
	return abs(x) < abs(y);
}
long long solve(long long n,int r)
{
    get_rongchi(r);
    long long ans = n;
    while(1)//
    {
        long long temp = calculate(ans);//保留下来的个数
        if(temp == n)
            break;
        ans += n - temp; //每次加上被删去的数的个数
    }
    return ans;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    int r,T;
    long long n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%d", &n, &r);
        printf("%lld\n",solve(n,r));
    }
    return 0;
}
