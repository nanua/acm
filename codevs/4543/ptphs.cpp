#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 0x3f3f3f3f, mod = 1e9 + 7;

class Splay_Tree{
public:
			
	int ch[maxn][2], F[maxn], Key[maxn], Sz[maxn], Rep[maxn], cnt, rt;

	int Newnode(int fa, int val) {
		++cnt;
		F[cnt] = fa, Key[cnt] = val, Rep[cnt] = Sz[cnt] = 1;
		return cnt;
	}
	
	inline int Typ(int x) { return ch[F[x]][0] == x; }
	inline void Update(int x) { Sz[x] = Sz[ch[x][0]] + Sz[ch[x][1]] + Rep[x]; }
		
	void Rotate(int x, int t) {
		int y = F[x];
		if (F[y]) ch[F[y]][Typ(y)^1] = x;
		ch[y][t^1] = ch[x][t];
		if (ch[x][t]) F[ch[x][t]] = y;
		ch[x][t] = y, F[x] = F[y], F[y] = x;
		Update(y), Update(x);
	}
	void Splay(int x, int f) {
		while (F[x] != f)
			if (F[F[x]] == f)
				Rotate(x, Typ(x));
			else {
				int y = F[x];
				if (Typ(y) != Typ(x))
					Rotate(x, Typ(x)), Rotate(x, Typ(x));
				else
					Rotate(y, Typ(y)), Rotate(x, Typ(x));
			}
		if (f == 0) rt = x;
	}
	
	inline int Gtp1(int x, int val) { return Key[x] <= val; }
	inline int Gtp2(int x, int val) { return Key[x] < val; }
	inline int Gtp3(int x, int val) { return Sz[ch[x][0]] + Rep[x] < val; }
	
	void Insert(int val) {
		int x = rt, typ = Gtp1(x, val);		
		while (ch[x][typ]) {
			Sz[x]++;
			if (Key[x] == val) return void(Rep[x]++);
			x = ch[x][typ], typ = Gtp1(x, val);
		}
		Sz[x]++;
		if (Key[x] == val) return void(Rep[x]++);
		ch[x][typ] = Newnode(x, val);
	}
	void Delete(int val) {
		int x = rt, typ = Gtp1(x, val);
		while (ch[x][typ]) {
			if (Key[x] == val) break;
			Sz[x]--;
			x = ch[x][typ], typ = Gtp1(x, val);
		}		
		if (Rep[x] > 1)
			{ Rep[x]--, Sz[x]--; return; }
		Splay(x, 0);
		int tsz = Sz[ch[x][0]];
		int prev = Get_Pos(tsz);
		Splay(prev, 0);
		int succ = Get_Pos(tsz+2);
		Splay(succ, prev);
		ch[succ][0] = 0;
		Update(succ), Update(prev);
	}

	int Get_Rank(int val) {
		int x = rt, typ = Gtp1(x, val);
		while (ch[x][typ]) {
			if (Key[x] == val) break;
			x = ch[x][typ], typ = Gtp1(x, val);
		}
		
		Splay(x, 0);
		return Sz[ch[x][0]] + 1;
	}
	int Get_Pos(int val) {
		int x = rt, typ = Gtp3(x, val);		
		while (ch[x][typ]) {
			if (Sz[ch[x][0]]+1 <= val && val <= Sz[ch[x][0]]+Rep[x]) break;
			if (Gtp3(x, val)) val -= Sz[ch[x][0]] + Rep[x];
			x = ch[x][typ], typ = Gtp3(x, val);
		}
		return x;
	}
	int Get_Prev(int val) {
		int x = rt, typ = Gtp2(x, val), ret = Key[x];
		while (x) {
			if (Key[x] < val) ret = Key[x];
			x = ch[x][typ];
			typ = Gtp2(x, val);
		}
		return ret;
	}

	int Get_Succ(int val) {
		int x = rt, typ = Gtp1(x, val), ret = Key[x];
		while (x) {
			if (Key[x] > val) ret = Key[x];
			x = ch[x][typ];
			typ = Gtp1(x, val);
		}
		return ret;
	}
	void Prog(int opt = 0, int val = 0) {
		cin >> opt >> val;
		
		switch(opt) {
		case 1: Insert(val); break;
		case 2: Delete(val); break;
		case 3: cout << Get_Rank(val)-1 << endl; break;
		case 4: cout << Key[Get_Pos(val+1)] << endl; break;
		case 5: cout << Get_Prev(val) << endl; break;
		case 6: cout << Get_Succ(val) << endl; break;
		}
	}
}Spl;

int main() {
	freopen("ptphs.in","r",stdin);
	freopen("ptphs.out","w",stdout);

	ios::sync_with_stdio(0);

	Spl.rt = Spl.Newnode(0, -inf);
	Spl.ch[Spl.rt][1] = Spl.Newnode(Spl.rt, inf);
	Spl.Update(Spl.rt);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		Spl.Prog();
}
