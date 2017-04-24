#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, nxt[] = {1, 2, 3, 0};

int T, n;
char str[3010], canvas[100][100];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d\n%s", &n, str);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) canvas[i][j] = '.'; //初始化画布
		
		int l = strlen(str), x = 1, y = 1, i = 0; //x, y是当前的座标
		while (i < l) {
			int flag = 1; //是否走到尽头
			for (int j = 0; j <= 3; ++j) { //枚举4个方向
				while (1 <= x && x <= n && 1 <= y && y <= n && canvas[x][y] =='.') {
					//座标是否在界内, 画布是否有被涂过.
					flag = 0;
					canvas[x][y] = str[i++];
					x = x + dx[j], y = y + dy[j]; //移动到相应的下一个座标
					if (i == l) goto Tag; //没有颜色了就退出
				}
				x -= dx[j]-dx[nxt[j]], y -= dy[j]-dy[nxt[j]]; //撤销刚才的步骤, 因为出来的时候一定是出界的
				//不要学这种用逗号把几个语句写在一行的做法......囧
			}
			if (flag) break; //如果一个点都没有涂, 那么就是走到头了.
		}
	Tag:;
		for (i = 1; i <= n; ++i, puts(""))
			for (j = 1; j <= n; ++j) putchar(canvas[i][j]); //输出画布
		puts(""); //puts("") 就是输出一个回车
	}
	return 0;
} 
