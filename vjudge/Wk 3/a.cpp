#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;
const int maxn = 1010, mod = 1e9 + 7;

ll ans, pow2[maxn] = {1}, inv2[maxn], f[maxn][maxn], sum[maxn][maxn];
int t, ks, n, d[maxn];

inline ll mul_mod(ll x, ll y) { return x * y % mod; }
inline ll pow_mod(ll x, ll y) {
	ll ret = 1;
	for (; y; y >>= 1, x = mul_mod(x, x))
		if (y & 1) ret = mul_mod(ret, x);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	for (int i = 1; i < maxn; ++i)
		pow2[i] = mul_mod(pow2[i-1], 2), inv2[i] = pow_mod(pow2[i], mod-2);

	cin >> t;
	for (int ks = 1; ks <= t; ++ks) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> d[i];
		memset(sum, 0, sizeof(sum));
		memset(f, 0, sizeof(f));
		f[1][1] = 1, sum[1][1] = inv2[2];
		
		for (int i = 2; i < n; ++i) {
			if (d[i] == 0)
				for (int j = 1; j <= i; ++j)
					f[i][j] = mul_mod((sum[i-1][i-1] - sum[i-1][j-1]), pow2[j+(j==1)]);
			else
				for (int j = 1; j <= i; ++j)
					f[i][j] = f[i-1][j-1];
			ll chk = 0;
			for (int j = 1; j <= i; ++j)
				sum[i][j] = (sum[i][j-1] + mul_mod(f[i][j], inv2[j+1])) % mod, chk += f[i][j];
			assert((chk % mod + mod) % mod == 1);
		}
		ans = 0;
		for (int i = 1; i < n; ++i) ans = (ans + mul_mod(f[n-1][i], inv2[i])) % mod;
		cout << "Case #" << ks << ": " << (ans%mod+mod)%mod << endl; 
	}	
}
