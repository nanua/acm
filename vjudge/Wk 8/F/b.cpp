#include <bits/stdc++.h>
#define CLR(x) memset(x, 0, sizeof(x))
#define lowbit(x) ((x)&(-(x)))
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10, lgmax = 22, inf = 0x3f3f3f3f;;

int cnt[maxn][lgmax], mexp[maxn], vis[maxn], isnprime[maxn], mfc[maxn], fcnt[maxn], lg[maxn];
char op[20];
int q, d, T;

inline void modify(int &x, int c, int ct) {
	if (c != 0) x |= (1 << ct);
	else x &= (~(1 << ct));
}
inline void try_modify(int x, int t) {
	if ((t == 1 && vis[x]) || (t == -1 && !vis[x])) return;
	vis[x] = (t == 1);	    
	for (int i = 1; i * i <= x; ++i)
		if (x % i == 0){
			cnt[i][fcnt[x/i]] += t, cnt[x/i][fcnt[i]] += t;
			modify(mexp[i], cnt[i][fcnt[x/i]], fcnt[x/i]);
			modify(mexp[x/i], cnt[x/i][fcnt[i]], fcnt[i]);
		}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif

	for (int i = 2; i < maxn; i *= 2) lg[i] = lg[i/2] + 1;
	for (ll i = 2; i < maxn; ++i)
		if (!isnprime[i])
			for (ll j = i*i; j < maxn; j += i)
				isnprime[j] = 1, mfc[j] = i;

	for (int i = 2; i < maxn; ++i)
		fcnt[i] = isnprime[i] ? fcnt[i/mfc[i]] + fcnt[mfc[i]] : 1;

	while(scanf("%d", &q), q) {
		printf("Case #%d:\n", ++T);
		CLR(cnt), CLR(mexp), CLR(vis);
		
		while (q--) {
			scanf("%s %d\n", op, &d);
			switch(op[0]) {
			case 'I':
				try_modify(d, 1); break;
			case 'D':
				try_modify(d, -1); break;
			case 'Q':
				int res = inf;
				for (int i = 1; i * i <= d; ++i)
					if (d % i == 0) {
						if (mexp[i]) res = min(res, fcnt[d/i] + lg[lowbit(mexp[i])]);
						if (mexp[d/i]) res = min(res, fcnt[i] + lg[lowbit(mexp[d/i])]);
					}
				printf("%d\n", res == inf ? -1 : res);
			}
		}
	}
}
