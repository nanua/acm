#include<bits/stdc++.h>
using namespace std;

int n = 100000, q = 100;
int main() {
	srand(time(NULL));
	freopen("in", "w", stdout);

	cout << n << " " << q << endl;
	for (int i = 1; i <= n; ++i) {
		cout << ((rand() * 100) + rand()) % (long long)1e8 << " ";
	}

	for (int i = 1; i <= q; ++i) {
		int l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) swap(l, r);
		cout << l << " " << r << endl;
	}
		
}
	     
