#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

stack<int> nxt;
int ans, vis[15];
int judge(int x);
void dfs(int need);

int main()
{
    int n;
    while(scanf("%d",&n) == 1&& n)
    {
        ans = 0;
        dfs(n);
        cout << ans << "\n";
    }
    cerr << 0x3f3f3f3f;
    return 0;
}

int judge(int x,int p)
{
    memset(vis,0,sizeof(vis));
    if(!x) return 1;
    int post = 1;
    while(x)
    {
        int q = x % 10;
        vis[post++] = q;
        for(int i = 1; i <= p; i++)
        {
            if(i == post - 1 || !vis[i]) continue;
            if(vis[i] == q|| (int)fabs(post - 1 - i) == (int)fabs(vis[post - 1] - vis[i]))
                return 0;
        }
        x /= 10;
    }
    return 1;
}

void dfs(int need)
{
    nxt.push(0);
    while(!nxt.empty())
    {
        int temp = nxt.top();
        nxt.pop();
        if(!judge(temp, need))  continue;
        if(temp / (int)pow(10,need - 1))
        {
            ans++;
            continue;
        }
        for(int i = 1; i <= need; i++)
        {
            nxt.push(temp * 10 + i);
        }
    }
}
