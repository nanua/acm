#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define swap(a, b) (a ^= b ^= a ^= b)
#define fi first
#define se second
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int q[maxn*4], vis[4*maxn], ec[11], cdr[11], b[11], hd, tl;

inline int encode(int *a) {
	int ret = 0;
	for (int i = 1, j, k; i <= 9; ++i) {		
		for (j = 1, k = 0; j <= i; ++j) k += a[j] <= a[i];
		ret += (a[i]-k) * ec[9-i];
	}
	return ret;		
}

inline void decode(int x, int *res) {
	int vis[10] = {};
	for (int i = 1, t, j; i <= 9; ++i) {
		t = x / ec[9-i];
		x %= ec[9-i];
		for (j = 1; j <= 9; ++j)
			if (!vis[j] && t-- == 0) break;
		res[i] = j, vis[j] = 1;
	}		
}

inline int __swap(int bg, int stp)  {
	bg--;
	int x[11];
	memcpy(x, cdr, sizeof(cdr));
		
	swap(x[bg+1], x[bg+4]), swap(x[bg+5], x[bg+1]), swap(x[bg+1], x[bg+2]);
	
	int ret = encode(x);	
	if (!vis[ret]) vis[ret] = stp+1, q[++tl] = ret;
	return ret;
}

void bfs() {
	hd = tl = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	q[++tl] = 0;
	while (++hd <= tl) {
		int x = q[hd];
		decode(x, cdr);
		int r[] = {1, 2, 4, 5};
		for (int i = 0; i < 4; ++i) __swap(r[i],  vis[x]);
	}	
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ec[0] = 1;
	for (int i = 1; i <= 9; ++i) ec[i] = ec[i-1] * i;
	bfs();
	while (~scanf("%d", b+1)) {
		for (int i = 2; i <= 9; ++i) scanf("%d", b+i);
		int ed = encode(b);
		printf("%d\n", vis[ed]-1);
	}
}
