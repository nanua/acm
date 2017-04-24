#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int l, m, n, kase, s, vsz;
int a[510], b[510], c[510], v[maxn*3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d %d %d\n", &l, &n, &m) == 3) {
		for (int i = 1; i <= l; ++i) scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		for (int i = 1; i <= m; ++i) scanf("%d", &c[i]);

		vsz = 0;

		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= n; ++j)
				v[++vsz] = a[i] + b[j];
		sort(v+1, v+vsz+1);

		scanf("%d", &s);

		printf("Case %d:\n", ++kase);
	     
		for (int i = 1, x; i <= s; ++i) {
			scanf("%d", &x);
			
			int ans = 0;
			for (int j = 1; !ans && j <= m; ++j)
				ans |= binary_search(v+1, v+vsz+1, x-c[j]);
			
			puts(ans ? "YES" : "NO");
		}		    
	}
}
 
