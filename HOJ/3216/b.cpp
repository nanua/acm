#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, nxt[] = {1, 2, 3, 0};

int T, n, i, j, x, y, l, flag;
char str[3010], canvas[100][100];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d\n%s", &n, str);
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j) canvas[i][j] = '.';
		
		l = strlen(str), x = 1, y = 1, i = 0; 
		while (i < l) {
			flag = 1; 
			for (j = 0; j <= 3; ++j) { 
				while (1 <= x && x <= n && 1 <= y && y <= n && canvas[x][y] =='.') {
					flag = 0;
					canvas[x][y] = str[i++];
					x = x + dx[j], y = y + dy[j]; 
					if (i == l) goto Tag; 
				}
				x -= dx[j]-dx[nxt[j]], y -= dy[j]-dy[nxt[j]]; 
				
			}
			if (flag) break; 
		}
	Tag:;
		for (i = 1; i <= n; ++i, puts(""))
			for (j = 1; j <= n; ++j) putchar(canvas[i][j]);
		puts(""); 
	}
	return 0;
}
