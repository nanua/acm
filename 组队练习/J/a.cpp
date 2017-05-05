#include <bits/stdc++.h>
using namespace std;

int main(){
	int cnt, n, v, r;
	cin >> cnt;
	while(cnt--){
		cin >> n >> v >> r;
		cout << fixed << setprecision(6) << 1.0 * r / double(v * sin(acos(-1) / n)) << "\n";
	}
	return 0;
}
