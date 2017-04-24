#include <bits/stdc++.h>
#define re register
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 258280327;
const int nxt[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int f[2][10][10], t, T, A, B, n, a[maxn];

inline void add_mod(int &x, const int &y) {
	x += y;
	if (x > mod) x -= mod;
}
inline int getint(char ch = getchar(), int ret = 0) {
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) ret = ret * 10 + ch - 48, ch = getchar();
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (scanf("%d", &T); T; T--) {
		scanf("%d %d %d", &n, &A, &B);		
		for (int i = 1; i <= n; ++i) a[i] = getint();

		memset(f, 0, sizeof(f));
		f[t = 0][0][0] = 1;
		for (re int i = 0; i < n; ++i, t ^= 1) {
			for (re int j = 0; j <= 9; ++j)
				for (re int k = 0; k <= 9; ++k)
					if (f[t][j][k] != 0){
						add_mod(f[t^1][nxt[j+a[i+1]]][k], f[t][j][k]);
						add_mod(f[t^1][j][nxt[k+a[i+1]]], f[t][j][k]);
					}
			memset(f[t], 0, sizeof(f[t]));
		}
		for (re int i = 1; i <= 9; ++i)
			for (re int j = 1; j <= 9; ++j)
				add_mod(f[t][i][j], f[t][0][A] + f[t][0][B]);
		printf("%d\n", f[t][min(A, B)][max(A, B)]);
	}
} 
