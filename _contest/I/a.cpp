#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
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

int m[3][3], n;

void m_mul(int x[3][3], int y[3][3]) {
	int tmp[3][3] = {};
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 2; ++j)
			for (int k = 1; k <= 2; ++k)
				(tmp[i][j] += x[i][k] * y[k][j] % 10000) %= 10000;
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 2; ++j)
			x[i][j] = tmp[i][j];
}

void m_qpow(int x) {
	int tmp[3][3] = {{}, {0, 1, 1}, {0, 1, 0}};
	for (; x; x >>= 1, m_mul(tmp, tmp))
		if (x & 1)
			m_mul(m, tmp);
}

int main() {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (gint(n), n != -1) {
		m[1][1] = m[2][2] = 1;
		m[1][2] = m[2][1] = 0;

		m_qpow(n);


		printf("%d\n", m[1][2] % 10000);
	}
}

