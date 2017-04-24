#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./gen"), system("./c"), system("./cmp");
		if (system("diff c.out cmp.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
 
