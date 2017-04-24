#include <bits/stdc++.h>
#define idx(x) (x-'a')
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7, sigma = 26;

struct ac_auto {
	int p[maxn][sigma], f[maxn], q[maxn], ed[maxn], sz;

	void init() {
		for (int i = 1; i <= sz; ++i)
			memset(p[i], 0, sizeof(p[i])), f[i] = ed[i] = 0;
		sz = 1;
	}

	void insert(char *s, int c = 1) {
#define ptr p[c][idx(s[i])]
		for (int i = 1; s[i]; c = ptr, ++i)
			if (ptr == 0) ptr = ++sz;
		ed[c] = 1;
	}

	void getfail() {
		int hr = 0, tl = 0;
		for (int i = 0; i < sigma; ++i)
			p[1][i] ? (f[q[++tl] = p[1][i]] = 1) : (p[1][i] = 1);

		while (++hr <= tl) {
			int &x = q[hr];
			ed[x] += ed[f[x]];
			for (int i = 0; i < sigma; ++i) {
				int &pt = p[x][i];
				pt ? (f[q[++tl] = pt] = p[f[x]][i]) : (pt = p[f[x]][i]);
			}
		}
	}

	int recog(char *s) {
		int ret = 0, c = 1;
		for (int i = 1; s[i]; c = p[c][idx(s[i++])])
			ret += ed[c];
		return ret;	
	}
}ac;

int T, n;
char str[maxn];

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif	
	for (scanf("%d\n", &T); T; T--) {
		scanf("%d\n",&n);
		
		ac.init();
		for (int i = 1; i <= n; ++i)
			scanf("%s", str), ac.insert(str);

		ac.getfail();

		scanf("%s",str);
		printf("%d\n", ac.recog(str));
	}
}
