void get_rev(int x){
	rev[x] ^= 1, swap(L(x), R(x));
}
int typ(int x){
	return !pre[x] ? -1 : x == L(pre[x]) ? 0 : x == R(pre[x]) ? 1 : 0;
}
void rot(int x){
	down(pre[x]), down(x);
	int y = pre[x], t = typ(x);
	ch[y][t] = ch[x][!t], ch[x][!t] = y;
	pre[x] = pre[y], pre[y] = x;
	if(typ(y) != -1) ch[pre[y]][typ(y)] = x;
	up(y), up(x);
}
void access(int x){
	for(int y = 0; x; )
		splay(x), y = x, x = pre[x], R(x) = y, up(y);
}
void asplay(int x){
	access(x), splay(x);
}
void evert(int x){
	asplay(x), get_rev(x);
}
int same_tree(int x, int y){
	evert(x), asplay(y);
	return x == y || pre[x] || pre[y];
}
void link(int x, int y){
	if(!same_tree(x, y)) pre[x] = y;
}
void cut(int x, int y){
	if(same_tree(x, y)) pre[x] = L(y) = 0;
}
