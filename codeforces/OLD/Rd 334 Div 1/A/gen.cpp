#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("in","w",stdout);
	srand(time(NULL));	
	int n = rand() % 500 + 1;
	cout << n << endl;
	for (int i = 1; i <= n; ++i)
		cout << rand() % 2;
}
