#include <bits/stdc++.h>
using namespace std;

char C[5] = {'N', 'E', 'W', 'S'};
int a[100100];
int main() {
	freopen("in.in","w",stdout);
	int n = 7;
	srand(time(NULL));
	cout << n << endl;
	a[0] = -1;
	for (int i = 1; i <= n; ++i) {
		while ((a[i] = rand()%4) + a[i-1] == 3);
		cout << C[a[i]];
	}
	cout << endl;
	a[0] = -1;
	for (int i = 1; i <= n; ++i) {
		while ((a[i] = rand()%4) + a[i-1] == 3);
		cout << C[a[i]];
	}
	cout << endl;
}
