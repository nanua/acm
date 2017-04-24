#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10, lgmax = 22, inf = 0x3f3f3f3f;

int cnt[maxn], mexp[maxn], vis[maxn], isnprime[maxn], mfc[maxn], fcnt[maxn], lg[maxn];
char op[20];
int q, d, T;
set<int> s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	for (int i = 2; i < maxn; i *= 2) lg[i] = lg[i/2] + 1;
	for (ll i = 2; i < maxn; ++i)
		if (!isnprime[i])
			for (ll j = i*i; j < maxn; j += i)
				isnprime[j] = 1, mfc[j] = i;

	for (int i = 2; i < maxn; ++i)
		fcnt[i] = isnprime[i] ? fcnt[i/mfc[i]] + fcnt[mfc[i]] : 1;

	while(scanf("%d", &q), q) {
		s.clear();
		printf("Case #%d:\n", ++T);
		while (q--) {
			scanf("%s %d\n", op, &d);
			switch(op[0]) {
			case 'I':
				s.insert(d); break;
			case 'D':
				if (s.find(d) != s.end()) s.erase(d); break;
			case 'Q':
				int res = inf;
				for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
					res = min(res, fcnt[*it] + fcnt[d] - 2*fcnt[__gcd(d, *it)]);

				cout << (res == inf ? -1 : res) << endl;
			}
		}
	}
}
