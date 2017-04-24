#include <cstdio>
#include <cstdlib>
#define Bg tlist[fr]

const int maxn = 1e6 + 10;

int T, t, ele, fr, tl;
int team[maxn], beg[maxn], sz[maxn], tlist[maxn], nxt[maxn], las[maxn];
char oper[100];

void add_ele(int t, int x) {
	if (!sz[t]) beg[t] = x, tlist[++tl] = t;
	nxt[las[t]] = x, las[t] = x;
	sz[t]++;
}
void pop_ele() {
	while (fr <= tl && sz[Bg] == 0) las[Bg] = 0, fr++;
	printf("%d\n", beg[Bg]-1);
	beg[Bg] = nxt[beg[Bg]], sz[Bg]--;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	while (scanf("%d",&t), t) {
		fr = 0, tl = 1;
		for (int i = 1, n; i <= t; ++i) {
			scanf("%d",&n);
			sz[i] = 0;
			for (int j = 1, tmp; j <= n; ++j)
				scanf("%d",&tmp), team[tmp+1] = i;
		}
		
		printf("Scenario #%d\n",++T);
		while (scanf("%s",oper), oper[0] != 'S') {
			switch (oper[0]) {
			case 'E': scanf("%d\n",&ele), add_ele(team[ele+1], ele+1); break;
			case 'D': pop_ele(); break;
			}
		}
		puts("");
	}
} 
