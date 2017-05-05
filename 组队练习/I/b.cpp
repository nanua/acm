#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 2e5+50, maxm = 1e5+50;
const int inf = 0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef int arrn[maxn];
typedef ll arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar()) {
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	ret *= sig;
}

int t, n, s, sz, d[1000];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	cin >> t;
	for (; t--; ) {
		cin >> n;
		for (int i = 1; ; ++i) {
			s = 0, sz = 0;
			for (int j = i; j; j /= 10)
				d[++sz] = j % 10, s += j % 10;
			if (s != n) continue;
			for (int j = 1; j <= sz; ++j)
				if (d[j] != d[sz-j+1]) goto gt;
			cout << i << endl;
			goto nt;
			gt:;
		}
		nt:;
	}
}
