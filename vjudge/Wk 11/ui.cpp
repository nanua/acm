#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;
#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define REP(i,a,b) for (int i = a ; i <= b ; ++i)
typedef long long LL;
const int det[4][2] = {{0,1},{1,1},{1,0},{1,-1}};
inline bool inmap (int x , int y , int n)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
pair<int,int> calc (int Map[MAXN][MAXN] , int n = 19 , int base = 50)
{
    LL score[MAXN][MAXN] = {};
    REP(t,0,3) FOR(i,n) FOR(j,n) if (inmap(i+det[t][0]*4,j+det[t][1]*4,n))
    {
        int st = 0;
        REP(k,0,4) st |= Map[i+k*det[t][0]][j+k*det[t][1]];
        LL tmp = st == 1 ? base : st == 2 ? 1 : 0;
        REP(k,0,4) if (Map[i+k*det[t][0]][j+k*det[t][1]]) tmp *= base*base;
        tmp /= base;
        REP(k,0,4) if (!Map[i+k*det[t][0]][j+k*det[t][1]]) score[i+k*det[t][0]][j+k*det[t][1]] += tmp;
    }
    FOR(i,n) FOR(j,n) score[i][j] += rand()%(base*base);
    pair<int,int> res;
    res.first = res.second = 1;
    FOR(i,n) FOR(j,n) if (score[i][j] > score[res.first][res.second])
        res.first = i, res.second = j;
    return res;
}

int mps[MAXN][MAXN];
int main(){
	int a, b;
      cout << "5 5" << endl;
	cin >> a >> b, mps[a][b] = 1;
	cout << "5 6" << endl;
	cin >> a >> b, mps[a][b] = 1;
	mps[5][5] = mps[5][6] = 2;
	while (cin >> a >> b, a != -1){
		mps[a][b] = 1;
		pair<int, int>res = calc(mps);
		mps[res.first][res.second] = 2;
		cout << res.first << " " << res.second << endl;
	}
}
