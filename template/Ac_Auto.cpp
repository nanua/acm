struct Acm{
	void ins(char *s){
		int x = 1;
		for(int i = 1; s[i]; x = ch[x][s[i]-'a'+1])
			if(!ch[x][s[i]-'a'+1]) ch[x][s[i]-'a'+1] = ++sz;
		end[x] = 1;
	}
	void get_fail(){
		int h = 0, t = 0;
		for(int i = 1; i <= sigma; ++i)
			ch[1][i] ? fail[q[++t] = ch[1][i]] = 1 : ch[1][i] = 1;
		while(h < t){
			int x = q[++h];
			for(int i = 1; i <= sigma; ++i){
				int &T = ch[x][i];
				T ? fail[q[++t] = T] = ch[fail[x]][i] : T = ch[fail[x]][i];
			}
		}
	}
	int match(char *str){
		for(int x = 1, i = 1; str[i]; ++i)
			x = ch[x][i], app[x] += end[x];
	}
}Ac;
