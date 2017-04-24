#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

char str1[maxn], str2[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%s %s",str1+1, str2+1) != EOF) {
		int n1 = strlen(str1+1), n2 = strlen(str2+1);
		
		for (int i = 1, j = 1; i <= n1 && j <= n2; ++i, ++j) {
			while (j <= n2 && str1[i] != str2[j]) ++j;
			if (j > n2) { puts("No"); goto gt;}
		}
		puts("Yes");
	gt:;
	}
}
 
