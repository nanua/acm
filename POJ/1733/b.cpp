#include <iostream>
#include <map>
using namespace std;

const int maxv = 1e4 + 15;
int par[3 * maxv], Rank[3 * maxv], v, e, cnt;
map<int, int> IDcache;
void init(){
	cnt = 0;
	IDcache.clear();
	for(int i=1;i<=3*maxv;i++) par[i]=i,Rank[i]=0; 
}
int ID(int x){
	return IDcache.count(x)?IDcache[x]:(IDcache[x]=++cnt);
}
int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}
void unite(int x, int y){
	x = find(x), y = find(y);
	if(Rank[x] < Rank[y]) par[x] = y;
	else{
		par[y] = x;
		if(Rank[x] == Rank[y]) Rank[x]++;
	}
}
bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("b.out", "w", stdout);
#endif
	while(cin >> v >> e){
		init();
		int ori, fin, flag = 1, ans = 0;
		for(int i = 1; i <= e; i++){
			char s[10];
			cin >> ori >> fin >> s;
			if(!flag) continue;
			int l = ID(ori - 1), r = ID(fin);
			if(s[0] == 'e'){
				unite(l,r),unite(l+maxv,r+maxv);
			}else if(s[0] == 'o'){
				unite(l,r+maxv),unite(l+maxv,r);
			}
			if(same(l,l+maxv)||same(r+maxv,r)) flag = 0;
			if(flag) ans = i;
		}
		if (flag) ans = e;
		cout << ans << "\n";
	}
	return 0;
} 
