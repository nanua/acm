#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;
vector<int> a;
vector<pair<int, vector<int> > > q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n = 9;
	for (int i = 1; i <= n; ++i) a.push_back(i);
	do {
		int tot = 0;
		for (int i = 1; i < n; ++i) tot += __gcd(a[i-1], a[i]);
		q.push_back(make_pair(tot, a));
		
	}while (next_permutation(a.begin(), a.end()));

	sort(q.begin(), q.end());

	for (int i = 0; i < q.size(); ++i){
		cout << i << " " << q[i].fi << endl;
		for (int j = 0; j < q[i].se.size(); ++j) cout << q[i].se[j] << " ";
		cout << endl << endl;
	}
}
