#include<cstdlib>
#include<cstdio>
using namespace std;
int n;
int main()
{
	while(1){
		system("./gen");
		system("./cmp");
		system("./ptphs");
		if(!system("diff cmp.out ptphs.out"))
			printf("%d ac\n",++n);
		else exit(0);
	}
} 
