#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n, m, i, j, k, h, key1[200001], key2[200001], ans[200001];
pair <int, int> a[200001], b[200001];
set <pair <int, int> > s;
set <pair <int, int> >::iterator it;
inline bool cmp1(int x, int y)
{
	return a[x].x < a[y].x;
}
inline bool cmp2(int x, int y)
{
	return b[x].x < b[y].x;
}
int main()
{
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		key1[i] = i;
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &b[i].x, &b[i].y);
		key2[i] = i;
	}
	sort(key1 + 1, key1 + n + 1, cmp1);
	sort(key2 + 1, key2 + m + 1, cmp2);
	h = m;
	for (k = n; k; k--)
	{
		i = key1[k];
		for (; h > 0 && b[j = key2[h]].x >= a[i].x; h--)
			s.insert(make_pair(b[j].y, j));
		it = s.lower_bound(make_pair(a[i].y, 0));
		if (it == s.end())
		{
			puts("-1");
			return 0;
		}
		else
		{
			ans[i] = it->y;
			s.erase(it);
		}
	}
	for (i = 1; i < n; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
	return 0;
}
