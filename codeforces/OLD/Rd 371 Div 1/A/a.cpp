#include <bits/stdc++.h>
#ifdef WIN32
#define fmt64 "%I64d"
#else
#define fmt64 "%lld"
#endif

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int n;
ll x;
char op[10];
map<int, int> Map;

inline int idx(ll x) {
	int res = 0;
	for (int i = 0; x; x /= 10, i++)
		res |= (x & 1) * (1 << i);
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> op >> x;
		switch(op[0]) {
		case '+': Map[idx(x)]++; break;
		case '-': Map[idx(x)]--; break;
		case '?': cout << Map[idx(x)] << endl; break;
		}
	}		
}
