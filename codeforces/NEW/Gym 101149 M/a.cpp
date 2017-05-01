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

int n, sz, q[101010], T[101010];
string s;

void build(int x, int l, int r) {
	if (l == r) return void(T[x] = l);
	int mid = (l + r) >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);

	printf("? %d %d\n", T[x<<1], T[x<<1|1]);
	fflush(stdout);
	cin >> s;
	T[x] = (s == "<" ? T[x<<1|1] : T[x<<1]);
}

void ask(int x, int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;

	if (T[x<<1] == T[x])
		q[++sz] = T[x<<1|1], ask(x<<1, l, mid);
	else
		q[++sz] = T[x<<1], ask(x<<1|1, mid+1, r);
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n;
	build(1, 1, n);
	ask(1, 1, n);

	int ans = q[1];
	for (int i = 2; i <= sz; ++i) {
		printf("? %d %d\n", ans, q[i]);
		fflush(stdout);
		cin >> s;
		if (s == "<") ans = q[i];
	}

	printf("! %d", ans);

}
