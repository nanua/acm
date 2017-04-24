#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n, a[1010], stk[1010], ssz;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (cin >> n, n) {
		while (cin >> a[1], a[1]) {
			for (int i = 2; i <= n; ++i) cin >> a[i], stk[i] = 0;

			ssz = 0;
			for (int i = 1, j = 1; i <= n; ) {
				if (ssz >= 1 && stk[ssz] == a[i]) { ssz--, i++; continue; }
				if (j > n) { puts("No"); goto gt; }
				while (j <= n && j != a[i]) stk[++ssz] = j++;
				if (j == a[i]) j++, i++;
			}
			puts("Yes");
		gt:;
		}
		puts("");
	}
}
 
