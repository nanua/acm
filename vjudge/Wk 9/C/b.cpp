#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int dig[maxn], dsz;
int pending(int x){
	int dsz = 0;
	for (int i = x; i; i /= 10) dig[++dsz] = i%10;	
	for (int i = 1, j = 1; i <= dsz; i = j+2) {
		while (j < dsz && (dig[j+1] & 1) == (dig[j] & 1)) ++j;
		if ((((j - i + 1) % 2) ^ (dig[j]&1)) == 0) return 0;
	}
	return 1;
}
ll Calc(ll x) {
	int ret = 0;
	for (int i = 1; i <= x; ++i)
		ret += pending(i);
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int T, L, R, t = 0;
	for (cin >> T; T; T--) {
		cin >> L >> R;
		cout << "Case #" << ++t << ": " << Calc(R) - Calc(L-1) << endl;
	}
}
