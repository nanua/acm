#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./gen"), system("./a"), system("./b");
		if (system("diff a.out cmp.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
 
