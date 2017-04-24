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

#define pb push_back
#define pk pop_back
#define fi first
#define se second

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;

const int maxn = 1e6+50, maxm = 1e5+50, inf = (int)0x3f3f3f3f, mod = (int)1e9 + 7;
const ll INF = (ll)1e17;

typedef ll arrn[maxn];
typedef ld arrm[maxn];


template<class Q> void gint(Q &ret, int sig = 1, char ch = getchar())
{
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') sig = -1, ch = getchar();
	for (ret = 0; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
		ret *= sig;
}

int n, m, k, a, b;
ld prz;
arrn c, tmp;
arrm val;
deque<int> maxq, smiq, minq;

void add_element_left(int x)
{
	while (maxq.size() && x - maxq.front() >= k)
		maxq.pop_front();
	while (maxq.size() && c[maxq.back()] <= c[x])
		maxq.pop_back();
	maxq.push_back(x);
}
void add_element_right(int x)
{
	while (minq.size() && minq.front() - x >= k)
		minq.pop_front();
	while (smiq.size() && smiq.front() - x >= k)
		smiq.pop_front();

	while (minq.size() && c[minq.back()] >= c[x])
	{
		int y = minq.back();
		minq.pop_back();
		if (c[x] == c[y]) continue;
		while (smiq.size() && c[smiq.back()] >= c[y])
			smiq.pop_back();
		smiq.push_back(y);
	}

	minq.push_back(x);
}
int main() {
 #ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
 #endif

	gint(n), gint(k), gint(a), gint(b);

	for (int i = 1; i <= n; ++i)
		gint(c[i]);
	c[n+1] = INF;

	for (int i = 1; i < k; ++i)
		add_element_left(i);

	for (int i = k; i <= n; ++i)
	{
		add_element_left(i);
		if (maxq.size())
			val[maxq.front()] += a;

	}

	for (int i = n; i > n-k+1; --i)
		add_element_right(i);
	for (int i = n-k+1; i >= 1; --i)
	{
		add_element_right(i);
		int t1 = n+1, t2 = n+1;
		if (minq.size() > 1) t1 = *(++minq.begin());
		if (smiq.size()) t2 = smiq.front();
		if (c[t1] > c[t2])
			val[t2] += b;
		else
			val[t1] += b;
	}

	double avr = 0;
	for (int i = 1; i <= n; ++i)
		if (val[i] != 0)
			m++, val[i] /= n-k+1, avr += val[i];
	avr /= m;

	for (int i = 1; i <= n; ++i)
		if (val[i] != 0)
			prz += (val[i] - avr) * (val[i] - avr);

	printf("%d %.4lf\n", m, prz / m);
}
