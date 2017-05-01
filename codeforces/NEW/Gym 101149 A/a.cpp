#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int t, ans = -1;
	for (int i = 1; i <= n; ++i) cin >> t, ans = max(ans, t);
	cout << ans;
}
