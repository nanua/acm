#include <cstdio>
#include <iostream>
using namespace std;

int n, k, b, tot;
int main() {
	while(cin >> n >> k) {
		for (tot = b = 0; n+b >= k; )
			b += n, tot += n, n = b / k, b %= k;
		cout << tot+n << endl;
	}	
}
