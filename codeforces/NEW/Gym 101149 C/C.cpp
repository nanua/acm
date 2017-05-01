 #include<bits/stdc++.h>
using namespace std;
int p, i, ans[1000000];
int main()
{
	scanf("%d", &p);
	memset(ans, -1, sizeof(ans));
	for (i = 0; i < p; i++)
		ans[(long long)i * (long long)i % p] = i;
	for (i = 0; i < p - 1; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[p - 1]);
	return 0;
}
