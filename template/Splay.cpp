#define L(x) ch[x][0]
#define R(x) ch[x][1]

void newnode(int x, int f, int t, int v){
	if(f) ch[f][t] = x;
	pre[x] = f;
	key[x] = v; 
}
int typ(int x){
	return x == L(pre[x]) ? 0 : 1;
}
void rot(int x){
	push_down(pre[x]), push_down(x);
	int y = pre[x], t = typ(x);
	ch[y][t] = ch[x][!t], ch[x][!t] = y;
	pre[ch[x][!t]] = y, pre[x] = pre[y], pre[y] = y ? x : 0;
	if(pre[y]) ch[pre[y]][typ(y)] = x;
	push_up(y), push_up(x);
}
void splay(int x, int t){
	while(pre[x] != t) rot(x);
	if(!t) root = x;
}
