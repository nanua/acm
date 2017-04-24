#include <bits/stdc++.h>
using namespace std;

set<int> s;
set<int>::iterator it;
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d", &n) == 1) {
		s.clear();
		
		for (int i = 1, t; i <= n; ++i) {
			scanf("%d", &t);
			if ((it = s.lower_bound(t)) == s.end()) s.insert(t);
			else s.erase(it), s.insert(t);    
		}

		cout << s.size() << endl;
	}
}
