#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

multiset<int> More;
multiset<int, greater<int> > Less;
int T, k, n, b[maxn], dsz;;

inline void modify(int &x) {
	Less.insert(x);
	while (Less.size() - More.size() >= 2)
		More.insert(*Less.begin()), Less.erase(Less.begin());

	while (More.size() && *More.begin() < *Less.begin())
		x = *More.begin(), More.insert(*Less.begin()),
			Less.insert(x), More.erase(More.find(x)), Less.erase(Less.begin());
	x = *Less.begin();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	for (cin >> T; T; T--) {
		cin >> k >> n;
		dsz = 0, More.clear(), Less.clear();

		for (int i = 1, t; i <= n; ++i) {
			cin >> t;
			modify(t);
			if (i & 1) b[++dsz] = t;
		}
		
		cout << k << " " << dsz << endl;
		for (int i = 1; i <= dsz; ++i)
			cout << b[i] << ((i % 10 && i != dsz) ? " " : "\n");
	}
}
