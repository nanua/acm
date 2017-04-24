#include <bits/stdc++.h>
#define gen() (rand() % mod)
using namespace std;


const int mod = 1e5;

void get1() {	
	int n = gen();
	cout << n << endl;
	for (int i = 2; i <= n; ++i)
		cout << rand() % (i-1) + 1 << " " << i << " " << rand() % int(10)+1 << endl;
	int q = rand() % 25 + 1;
	cout << q << endl;
	for (int i = 1; i <= q; ++i) cout << rand() % 5 << endl;
	cout << endl;
}
int main() {
	freopen("c.in","w",stdout);
	srand(time(0));

	puts("3");
	get1();
	get1();
	get1();
}
 
