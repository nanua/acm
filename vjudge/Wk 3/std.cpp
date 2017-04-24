#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007 , a2 = 500000004;
LL A[1003] , F[1003][1003] ;

int main (void)
{
	freopen("in.in","r",stdin);
	freopen("cmp.out","w",stdout);
    int t , n ;
    cin >> t;
    for (int Cas = 1 ; Cas <= t ; ++Cas)
    {
        memset(F,0,sizeof(F));
       
        cin >> n;
        for (int i = 1 ; i <= n ; ++i)
            cin >> A[i];
        
        F[0][0] = F[1][1] = 1;
        
        for (int i = 2 ; i < n ; ++i)
        {
            if (A[i] == 1)
            {
                for (int j = 2 ; j <= i ; ++j)
                    F[i][j] = F[i-1][j-1];
            }
            else
            {
                F[i][i-1] = (F[i-1][i-1] * a2) % MOD;
                for (int j = i - 2 ; j > 1 ; --j)
                    F[i][j] = ((F[i][j+1] + F[i-1][j]) * a2) % MOD;
                F[i][1] = (F[i][2] + F[i-1][1]) % MOD;
            }
        }
        LL ans = F[n-1][0];
        for (LL i = 1 , x = a2 ; i <= n - 1 ; ++i)
        {
            ans = (ans + F[n-1][i] * x) % MOD;
            x = (x * a2) % MOD;
        }
        if (n <= 1) ans = 1; else if (n == 2) ans = a2;
        cout << "Case #" << Cas << ": " << ans << endl;
    }
    return 0;
}
