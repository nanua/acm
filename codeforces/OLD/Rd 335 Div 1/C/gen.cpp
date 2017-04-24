#include<bits/stdc++.h>
using namespace std;

int maxn = 5e3, maxp = 1e6, maxq = 1e2;

int main() {
	freopen("in.in","w",stdout);
	srand(time(NULL));
	int n = rand() % maxn + 1, p = rand() % maxp + 1, q = rand() % maxp + 1;
	cout << n << " " << p << " " << q << endl;
	for (int i = 1; i <= n; ++i)
		cout << rand() % maxq + 1 << " " << rand() % maxq + 1 << endl;	
}
