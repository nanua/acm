#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

string str;
int T, ans, kase;
vector<int> d[30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for (cin >> T; T; T--) {
		cin >> str;
		
		ans = inf;
		for (int i = 0; i < 26; ++i) d[i].clear();
		
		for (int i = 0; i < (int)str.size(); ++i)
			d[str[i]-'a'].push_back(i);
		
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < (int)d[i].size()-1; ++j)
				ans = min(ans, d[i][j+1] - d[i][j]);

		printf("Case #%d: %d\n", ++kase, ans == inf ? -1 : ans);
	}
}
 
