#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, d, s, t, tmp;
void ex_gcd(ll &s, ll &t, ll &d, ll x, ll y) {
	if (y == 0) d = x, s = 1, t = 0;
	else ex_gcd(t, s, d, y, x%y), t -= s*(x/y);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("2669.in","r",stdin);
	freopen("2669.out","w",stdout);
#endif
	while (cin >> x >> y) {
		ex_gcd(s, t, d, x, y);
		if (s < 0) tmp = (s / y + 1)*y, s += tmp, t -= tmp*x/y;
		if (d != 1) puts("sorry");
		else cout << s << " " << t << endl;
	}
}
 

