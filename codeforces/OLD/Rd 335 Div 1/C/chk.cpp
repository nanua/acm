#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int main() {
	for(;;) {
		system("./gen");
		system("./C");
		system("./std");
		if (system("fc out.out std.out"))
			puts("Wa"), exit(0);
		else
			cerr << ++cnt << "Ac" << endl;;
		
	}
}
