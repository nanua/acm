#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> Q;
typedef pair<int, Q> P;
const int maxn = 3e3 + 15;
int n, m, a[maxn];
set<P> st;
set<Q> used;

int main(){
	while(scanf("%d %d", &n, &m) == 2){
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1, greater<int>() );
		st.clear(), used.clear();
		st.insert(P(a[1] + a[2], Q(1, 2)));
		int cnt = 0;
		while(true){
			P now = *st.rbegin();
			cnt++;
			printf("%d%c",now.fi,cnt==m?'\n':' ');
			if(cnt == m) break;
			used.insert(now.second);
			st.erase(now);
			if(now.second.fi + 1 < now.second.second){
				P New = P(now.fi, Q(now.second.fi + 1, now.second.second));
				if(!used.count(New.second)) st.insert(New);
			}
			if(now.second.second < n){
				P New = P(now.fi, Q(now.second.fi, now.second.second + 1));
				if(!used.count(New.second)) st.insert(New);
			}
		}
	}
	return 0;
}
