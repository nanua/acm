#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int T, a, b;
int s[100], d[100];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (a = 1; a <= 100; ++a)
		for (b = 1; b <= 100; ++b) {
			// printf("%d %d\n     ", a, b);
			for (int i = 1; i <= 9; ++i)
				s[i] = (2*b-a)*i - 9*b*(i>=5); // printf("%d ", s[i]);
			// puts("\n");
			if (*min_element(s+1, s+10) > 0 || *max_element(s+1, s+10) < 0)
				{ puts("0"); goto gt; } 
			for (int i = 1, j, k; i < 3e6; ++i) {
				for (j = 0, k = i; k; k /= 10) d[++j] = k % 10;
				int ans = 0;
				for (k = 1; k <= j; ++k) ans += s[d[k]];
				if (ans == 0) {
					cerr << a << " " << b << " " << i << endl;
					cout << a << " " << b << " " << i << endl;
					goto gt;
				}
			}
		gt:;
				
		}
}
 
