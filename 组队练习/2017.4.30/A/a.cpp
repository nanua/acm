#include <bits/stdc++.h>
using namespace std;
const char S[] = "niega";
int T, n, ans, i, j;
char s[100010];
bool flag;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		n = strlen(s);
		ans = 0;
		for (i = 0; i < n - 4; i++)
		{
			flag = true;
			for (j = i; j < i + 5; j++)
				if (s[j] != S[j - i])
					flag = false;
		    if (flag)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
