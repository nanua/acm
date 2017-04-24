#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>v;
multiset<int>S1;
int main()
{
	freopen("ptphs.in","w",stdout);
	srand(time(NULL));
	int N = 1e5;
	cout << N << endl;
	for(int i = 1; i <= N; ++i){
	Gt:int op = rand() % 10;
		if(op <= 3 && S1.size() >= 5000) goto Gt;
		if(op <= 3){
			int n = rand() % 10 + 1;
			S1.insert(n);
			printf("1 %d\n",n);
			continue;
		}
		if(S1.size() < 2) goto Gt;
		if(op == 4 || op == 5){
			int n = rand() % (*S1.rbegin());
			printf("2 %d\n",*S1.lower_bound(n));
			S1.erase(S1.lower_bound(n));
			continue;
		}
		if(op == 6){
			int n = rand() % (*S1.rbegin());
			printf("3 %d\n",*S1.lower_bound(n)); 
			continue;
		}
		if(op == 7){
			int n = rand() % S1.size() + 1;
			printf("4 %d\n",n);
			continue;
		}
		if(op == 8){
			int n = rand() % *S1.begin() + *S1.begin() + 1;
			printf("5 %d\n",n);
			continue;
		}
		if(op == 9){
			int n = rand() % *S1.rbegin();
			printf("6 %d\n",n);
			continue;
		}
	}
	return 0;
} 
