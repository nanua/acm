#include <bits/stdc++.h>
using namespace std;
int p[1000100];
int main() {
	freopen("a.in","w",stdout);
	srand(time(0));
	int n = 6, maxp = 30;
	cout << n << endl;
	for (int i = 1; i <= n; ++i) p[i] = rand() % maxp;
	sort(p+1, p+n+1);
	for (int i = 1; i <= n; ++i) cout << p[i] << " ";
}
