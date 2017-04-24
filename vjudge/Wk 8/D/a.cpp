#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

char str[maxn];
int n;
ll ans = 1, cnt[maxn];
inline int idx(char ch) {
	if (isdigit(ch)) return ch - '0';
	if (isupper(ch)) return ch - 'A' + 10;
	if (islower(ch)) return ch - 'a' + 36;
	return (ch == '-' ? 62 : 63);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%s",str+1);
	for (int i = 0; i <= 63; ++i)
		for (int j = 0; j <= 63; ++j)
			cnt[i&j]++;
	n = strlen(str+1);
	for (int i = 1; i <= n; ++i)
		(ans *= cnt[idx(str[i])]) %= mod;
	cout << ans;
}
 
