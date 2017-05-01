#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 15;
vector<int> pos[maxn];
int v, e, ori, fin, vis[maxn];

int main(){
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif

	scanf("%d %d", &v, &e);
	for(int i = 1; i <= e; i++){
		scanf("%d %d", &ori, &fin);
		pos[ori].push_back(fin), pos[fin].push_back(ori);
	}
	int ans = -1, index = -1;
	for(int i = 1; i <= v; i++){
		if(ans < v - 1 - (int)pos[i].size()){
			ans = v - 1 - (int)pos[i].size();
			index = i;
		}
	}
	fill(vis + 1, vis + v + 1, true);
	vis[index] = false;
	for(int i = 0; i < (int)pos[index].size(); i++) vis[pos[index][i]] = false;
	for(int i = 1; i <= v; i++) printf("%d ", vis[i]);
	return 0;
}
