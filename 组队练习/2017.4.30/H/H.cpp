#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, t, tot, tmp, i, num[500010];
char s[500010];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (i = 1; i <= n; i++)
	{
		if (s[i] == '(')
		{
			a++;
			num[i] = 1;
		}
		if (s[i] == ')')
		{
			b++;
			num[i] = -1;
		}
		if (s[i] == '?')
			c++;
	}
	if ((a - b + c) % 2 == 1)
	{
		puts("Impossible");
		return 0;
	}
	t = (c + b - a) >> 1;
	for (i = 1; i <= n; i++)
	{
		if (num[i] == 0)
		{
			tot++;
			if (tot <= t)
			{
				s[i] = '(';
				num[i] = 1;
			}
			else
			{
				s[i] = ')';
				num[i] = -1;
			}
		}
		if ((tmp += num[i]) < 0)
		{
			puts("Impossible");
			return 0;
		}
	}
	puts(s + 1);
	return 0;
}
