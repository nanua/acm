#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int n = 1; ; n++) {
		system("./gen"), system("./b"), system("./c");
		if (system("diff a.out h.out"))
			puts("WA"), exit(0);
		else
			cout << n << "AC" << endl;
	}
}
