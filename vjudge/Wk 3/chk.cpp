#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 1; ; ++i) {
		system("./gen"), system("./std"), system("./a");
		if (system("diff out.out cmp.out"))
			puts("Wa"), exit(0);
		else
			cout << i << endl;
	}
		
}
