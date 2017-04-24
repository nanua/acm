#include <stdio.h>
char ch;
int typ;
int main() {
	while ((ch = getchar()) != EOF)
		ch == '"' ? (printf((typ^=1) ? "``" : "''")) : putchar(ch);
	return 0;
} 
