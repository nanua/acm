#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200005;
int C[N], n;
char str[10];

int lowbit(int x) {
    return x & (-x);
}

int Sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

void Add(int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}

int main() {
    int cas = 0;
    while (scanf("%d", &n) == 1 && n) {
        memset(C, 0, sizeof(C));
        int x, a, b;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            Add(i, x);
        }
        if (cas)    
            printf("\n");
        printf("Case %d:\n", ++cas);
        while (scanf("%s", str) && str[0] != 'E') {
            scanf("%d%d", &a, &b);
            if (str[0] == 'M')
                printf("%d\n", Sum(b) - Sum(a - 1));
            else {
                x = Sum(a) - Sum(a - 1);
                int temp = b - x;
                Add(a, temp);
            }
        }
    }
    return 0;
}
