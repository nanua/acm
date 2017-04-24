#include <bits/stdc++.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

typedef long double dbl;
const int maxn = 1e3 + 10;

int n, m, rk[maxn];;
dbl prob, ans, pts, f[maxn*maxn], sum[maxn*maxn], frac[maxn];

dbl calc(int k) {
	dbl x = k * log(max(prob,1e-25)), y = (m-k-1) * log(max(1-prob,1e-25)), z = frac[m-1] - frac[m-k-1] - frac[k];
	return exp(x+y+z);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) frac[i] = frac[i-1] + log(i);
	for (int i = 1; i <= n; ++i) cin >> rk[i], pts += rk[i];

	for (int i = 1; i <= m; ++i) f[i] = 1.0 / (m-1);
	f[rk[1]] = 0;
		
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m*i; ++j) sum[j] = sum[j-1] + f[j];
		for (int j = m*i; j >= 1; --j)
			f[j] = (sum[j-1] - sum[max(j-m-1, 0)] - f[max(j-rk[i], 0)]) / (m-1);
	}

	for (int i = n; i < pts; ++i) prob += f[i];
	for (int i = m-1; i >= 1; --i) ans += calc(i) * i;
	
	cout << fixed << setprecision(15) << ans + 1;		
}
