#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n = 9, a[30];
	double tot, cnt;
	for (int i = 1; i <= n; ++i) a[i] = i;
	do {
		tot = cnt = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j){
				
				for (int k = i; k <= j; ++k)
					for (int l = k+1; l <= j; ++l)
						cnt += a[k] > a[l];
				tot += 1;
			}
		cout << cnt << "/" << tot << endl;				
	}while (next_permutation(a+1, a+n+1));
}

