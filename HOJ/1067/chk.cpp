#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./gen"), system("./c"), system("./b");
		if (system("diff c.out b.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
