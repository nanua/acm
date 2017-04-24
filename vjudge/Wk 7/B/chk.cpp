#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./gen"), system("./b"), system("./cmp");
		if (system("diff b.out c.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
 
