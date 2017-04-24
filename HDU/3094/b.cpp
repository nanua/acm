#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 15;
vector<int> pos[maxn];
int n, k, ori, fin, vis[maxn], SG[maxn];
void init(){
	memset(SG, -1, sizeof(SG));
	for(int i = 1; i <= n; i++) pos[i].clear();
}
int query(int x, int pre){
	if(SG[x] != -1) return SG[x];
	memset(vis, 0 ,sizeof(vis));
	for(int i = 0; i < pos[x].size(); i++) if(pos[x][i] != pre)
	vis[query(pos[x][i], x)] = 1;
	for(int i = 0; ; i++) if(!vis[i]) return (SG[x] = i);
}

int main(){
	while(scanf("%d %d", &n, &k) == 2){
		init();
		for(int i = 1; i < n; i++){
			scanf("%d %d", &ori, &fin);
			pos[ori].push_back(fin), pos[fin].push_back(ori);
		}
		if(!query(k, 0)) printf("First player loses\n");
		else{
			int ans = maxn;
			for(int i=0;i<pos[k].size();i++) if(!SG[pos[k][i]]) ans=min(ans,pos[k][i]);
			printf("First player wins flying to airport %d\n", ans);
		}
	}
	return 0;
}
