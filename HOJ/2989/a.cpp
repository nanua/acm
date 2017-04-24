#include <stdio.h>
#include <stdlib.h>

int n, k, i;

int main() {
	while (scanf("%d %d", &n, &k), k) {
		for (i = k-1; i >= 0; --i)
			puts((n & (1<<i)) ? "- -" : "---");
		puts("");
	}
}
