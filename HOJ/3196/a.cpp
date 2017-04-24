#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 15;
int post[maxn], dp[maxn], tests, n;

int main()
{
	scanf("%d", &tests);
	while(tests--)
	{
		scanf("%d", &n) == 1;
		for(int i = 1; i < n; i++) scanf("%d", &post[i]);
		for(int i = 1; i <= n; i++)
		{
			int ans = 0;
			for(int j = 1; i - 2 * j >= 0 && j <= 200; j++)
			    ans = max(ans, dp[i - 2 * j] + post[i - j]);
			dp[i] = max(ans, dp[i - 1]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
