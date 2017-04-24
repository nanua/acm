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
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m, f[maxn], t[maxn];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void _union(int x, int y) {
	f[find(x)] = f[find(y)];
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d %d\n",&n,&m), n) {
		for (int i = 1; i <= n; ++i) f[i] = i;
		
		for (int i = 1, j; i <= m; ++i) {
			scanf("%d",&j);
			for (int k = 1; k <= j; ++k) scanf("%d",&t[k]), t[k]+=1;
			for (int k = 2; k <= j; ++k) _union(t[k], t[1]);
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (find(i) == find(1)) cnt++;
		printf("%d\n", cnt);
	}
}
 
