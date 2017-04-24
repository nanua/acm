#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("ans.out","w",stdout);
#endif
	for (int i = 1; i <= 10; ++i)
		cout << i - (i&-i) + 1 << endl;
}
 
