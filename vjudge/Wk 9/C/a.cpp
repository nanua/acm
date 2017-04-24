#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[20][2][2][2][2], L, R;
bool vis[20][2][2][2][2];
int dig[20], dsz, T, t;

ll dfs(int cur, int dod, int lod, int lim, int strr) {
	if (cur > dsz) return (((dod^lod) == 1) || strr == 1);
	if (vis[cur][dod][lod][lim][strr])
		return f[cur][dod][lod][lim][strr];
	
	vis[cur][dod][lod][lim][strr] = 1;
	
	ll &F = f[cur][dod][lod][lim][strr];
	int nlim = lim ? dig[cur] : 9;

	for (int i = 0; i <= nlim; ++i)
		if ((((i&1) ^ dod) == 1 && (dod^lod) == 1)
		    || strr == 1
		    || ((i&1)^dod) == 0) {
			int nlen = ((i&1) ^ dod) == 0 ? lod^1 : 1;
			if (strr && (i != 0)) nlen = 1;
			F += dfs(cur+1, i&1, nlen, lim && (i == dig[cur]), strr && (i == 0));
		}

	return F;
}
ll Calc(ll x) {
	dsz = 0;
	memset(f, 0, sizeof(f));
	memset(vis, 0, sizeof(vis));
	
	for (ll i = x; i; i /= 10) dig[++dsz] = i % 10;
	reverse(dig+1, dig+dsz+1);
	
	ll ret = 0;
	ret = dfs(1, 0, 0, 1, 1);//前 i, 数字奇偶, 长度奇偶, 顶格, 起始0
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (cin >> T; T; T--) {
		cin >> L >> R;
		cout << "Case #" << ++t << ": " << Calc(R) - Calc(L-1) << endl;
	}
}
