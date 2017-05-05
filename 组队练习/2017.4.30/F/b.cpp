#include <bits/stdc++.h>
using namespace std;
int T, n, i, j, x[100001], y[100001], f[100001];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("b.out", "w" ,stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			x[i] -= i;
			y[i] -= i;
		}
		for (i = 1; i <= n; i++)
		{
			f[i] = 1;
			for (j = 1; j < i; j++)
				if (x[i] >= x[j] && y[i] >= y[j])
					f[i] = max(f[i], f[j] + 1);
		}
		printf("%d\n", n - *max_element(f+1,f+n+1));
	}
	return 0;
}
