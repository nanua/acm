#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

priority_queue<ll> gre;
priority_queue<ll, vector<ll>, greater<ll> > les;
int n;

template<class T> inline void get(T &q) {
	ll x = q.top(); q.pop();
	ll y = q.top(); q.pop();
	q.push(x * y + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	while (cin >> n, n) {
		if (gre.size()) gre.pop(), les.pop();
		for (int i = 1, t; i <= n; ++i)
			cin >> t, gre.push((ll)t), les.push((ll)t);

		while (gre.size() > 1)
			get(gre), get(les);

		cout << les.top() - gre.top() << endl;
	}
}
 
