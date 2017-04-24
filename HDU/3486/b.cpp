
//**********************RMQ
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 200005;
int ma[22][maxn], a[maxn], Log[maxn];
int n, m, k;
int two[22];
void RMQ_init() {
    int i, j;
    Log[0] = -1;
    for(i = 1; i < maxn; i++)
        Log[i] = Log[i>>1] + 1;
   // for(i = 1; i <= n; i++)
   //     ma[0][i] = a[i];
    for(j = 1; j <= Log[n]; j++) {
        int x = n-two[j]+1;
        for(i = 1; i <= x; i++) {
            int y = i+(two[j] >>1);
            ma[j][i] = max(ma[j-1][i], ma[j-1][y]);
        }
    }
}
int RMQ(int l, int len) { // flag 1: max     0 min
    int k = Log[len];
    return max(ma[k][l], ma[k][l+len-two[k]]);
}
int sum[maxn];
int main() {
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    int i, j;
    two[0] = 1;
    for(i = 1; i <= 20; i++) two[i] = two[i-1] << 1;
    while( ~scanf("%d%d", &n, &k)) {
        if(n < 0 && k < 0) break;
        sum[0] = 0;
        int MAX = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &ma[0][i]);
            sum[i] = sum[i-1]+ma[0][i];
            MAX = max(MAX, ma[0][i]);
        }
        if(sum[n] <= k) {
            puts("-1");
            continue;
        }

        RMQ_init();
        int ans = n;
        int pos = k/MAX;
        if(!pos) pos++;
        int ff = n>>1;
        for(i = pos; i <= ff; i++) {
            j = n/i;
            int s = 0;
            for(int x = 0; x < i; x++) {
                s += RMQ(x*j+1, j);

                if(s > k) break;
            }
            if(s > k) {
                ans = i;
                break;
            }
        }
        if(ans != n) {
            printf("%d\n", ans);
            continue;
        }
        for(i = ff+1; i <= n; i++) {
            if(sum[i] > k) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
