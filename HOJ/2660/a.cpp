#include <cstdio>
#include <cctype>
#include <cstdlib>

char ch = getchar();
int cnt, flag;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	for(;;) {
		while (!isalpha(ch) && ch != -1) ch = getchar();
		if (ch == -1) exit(0);
		flag = 0;
		cnt = 0;
		while (isalpha(ch) || ch == ' '){
			if (isalpha(ch)) for (int i = 1; i <= cnt; ++i) putchar(' ');
			else break;
			cnt = 0;
			while (isalpha(ch)) putchar(ch), ch = getchar(), flag = 1;
			while (ch == ' ') cnt++, ch = getchar();
		}
		if (flag) puts("");
	}
}
