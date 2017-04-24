#include <bits/stdc++.h>
using namespace std;

const int pri[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
int a[41], vis[41], n, kase;

inline void putint(int x) {
	if (x != 0) (putint(x/10), putchar('0'+x%10));
}
void dfs(int d, int l) {
	if (d == l+1) {
		if (pri[a[1]+a[l]]) {
			for (register int i = 1; i <= l; ++i)  {
				if(i != 1) putchar(' ');
				putint(a[i]);
			}
			
			puts("");			
		}
		return;
	}

	for (register int i = 1; i <= l; ++i)
		if (!vis[i] && pri[a[d-1]+i]) vis[i] = 1, a[d] = i, dfs(d+1, l), vis[i] = 0;	
}
int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	a[1] = 1, vis[1] = 1;
	while (cin >> n) {
		cout << "Case " << ++kase << ":\n";
		if (n % 2 == 0) dfs(2, n);
		cout << endl;
	}
}
