#include <bits/stdc++.h>
using namespace std;
const int SIZE = 26;
int T, n, m, opt, x, y, num, a[100001], s[100001], f[100001], Bin[SIZE], son[3000001][2];
void Convert(int x)
{
	for (int i = 0; i < SIZE; i++)
	{
		Bin[SIZE - i - 1] = x & 1;
		x >>= 1;
	}
}
void Insert(int p, int x)
{
	Convert(x);
	for (int i = 0; i < SIZE; i++)
	{
		if (!son[p][Bin[i]])
			son[p][Bin[i]] = ++num;
		p = son[p][Bin[i]];
	}
}
int Query(int p, int x)
{
	Convert(x);
	int ans = 0;
	for (int i = 0; i < SIZE; i++)
		if (son[p][!Bin[i]])
		{
			p = son[p][!Bin[i]];
			ans = (ans << 1) + 1;
		}
		else
		{
			p = son[p][Bin[i]];
			ans <<= 1;
		}
	return ans;
}
void DFS(int p, int q, int x)
{
	for (int i = 0; i < 2; i++)
		if (son[q][i])
		{
			if (!son[p][i])
				son[p][i] = son[q][i];
			DFS(son[p][i], son[q][i], (x << 1) + i);
		}
}
int Get(int p)
{
	if (f[p] != p)
		f[p] = Get(f[p]);
	return f[p];
}
void Merge(int p, int q)
{
	p = Get(p);
	q = Get(q);
	if (p == q)
		return;
	if (s[p] < s[q])
		swap(p, q);
	DFS(p, q, 0);
	s[p] += s[q];
	f[q] = f[p];
}
int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		num = n;
		memset(son, 0, sizeof(son));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			Insert(f[i] = i, a[i]);
			s[i] = 1;
		}
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d%d", &opt, &x);
			if (opt == 1)
			{
				scanf("%d", &y);
				Merge(x, y);
			}
			else
				printf("%d\n", Query(Get(x), a[x]));
		}
	}
	return 0;
}
