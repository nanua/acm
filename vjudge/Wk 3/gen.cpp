#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.in","w",stdout);
	srand(time(0));
	int ks = 10;
	cout << ks << endl;
	for (int k = 1; k <= ks; ++k) {
		int n = 200;
		cout << n << endl;
		for (int i = 1; i <= n; ++i) cout << (rand() & 1) << " ";
	}
}
