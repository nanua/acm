#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
struct data
{
	char ch[6][6];
	int time,stat;
}st,tt;
bool operator <(data a,data  b)
{
	int i,j;
	for(i=1;i<=4;++i)     
		for(j=1;j<=4;++j)
			if(a.ch[i][j]!=b.ch[i][j])return a.ch[i][j]<b.ch[i][j];
	return 0;
}
struct location
{
	int x,y;       
}loc;  
queue<data>Q;
set<data>S;
data temp,tem2;
int ser;
int i,j,kk;
string s;
int pd(int i,int j,int stat)
{
	if(stat==0)
		if(temp.ch[i+1][j]=='O' || temp.ch[i-1][j]=='O'|| temp.ch[i][j+1]=='O' || temp.ch[i][j-1]=='O' )
			return 1;
		else return 0;
	if(stat==1)
		if(temp.ch[i][j]=='W')
			if(temp.ch[i+1][j]=='O' || temp.ch[i-1][j]=='O'|| temp.ch[i][j+1]=='O' || temp.ch[i][j-1]=='O' )
				return 1;
			else return 0;
		else return 0;
	if(stat==2)
		if(temp.ch[i][j]=='B')
			if(temp.ch[i+1][j]=='O' || temp.ch[i-1][j]=='O'|| temp.ch[i][j+1]=='O' || temp.ch[i][j-1]=='O' )
				return 1;
			else return 0;
		else return 0;     
}
location find(int i,int j)
{
	location res;
	if(tem2.ch[i+1][j]=='O'){res.x=i+1;res.y=j;return res;}
	if(tem2.ch[i-1][j]=='O'){res.x=i-1;res.y=j;return res;}
	if(tem2.ch[i][j+1]=='O'){res.x=i;res.y=j+1;return res;}
	if(tem2.ch[i][j-1]=='O'){res.x=i;res.y=j-1;return res;}         
}
int bingo(data a)
{
	int i;
	for(i=1;i<=4;++i)
		{
			if((a.ch[i][1]=='W'&&a.ch[i][2]=='W'&&a.ch[i][3]=='W'&&a.ch[i][4]=='W')||
			   (a.ch[i][1]=='B'&&a.ch[i][2]=='B'&&a.ch[i][3]=='B'&&a.ch[i][4]=='B'))
				return 1;
			if((a.ch[1][i]=='W'&&a.ch[2][i]=='W'&&a.ch[3][i]=='W'&&a.ch[4][i]=='W')||
			   (a.ch[1][i]=='B'&&a.ch[2][i]=='B'&&a.ch[3][i]=='B'&&a.ch[4][i]=='B'))
				return 1;
		}
	if((a.ch[1][1]=='W'&&a.ch[2][2]=='W'&&a.ch[3][3]=='W'&&a.ch[4][4]=='W')||
	   (a.ch[1][1]=='B'&&a.ch[2][2]=='B'&&a.ch[3][3]=='B'&&a.ch[4][4]=='B'))
		return 1;
	if((a.ch[1][4]=='W'&&a.ch[2][3]=='W'&&a.ch[3][2]=='W'&&a.ch[4][1]=='W')||
	   (a.ch[1][4]=='B'&&a.ch[2][3]=='B'&&a.ch[3][2]=='B'&&a.ch[4][1]=='B'))
		return 1;
	return 0;
}
void BFS()
{

	Q.push(st);
	do
		{
			temp=Q.front();
			Q.pop();
			for(i=1;i<=4;++i)
				for(j=1;j<=4;++j)
					{  if(temp.stat==0)ser=0;
						else if(temp.stat==1)ser=1;
						else ser=2;
						kk=pd(i,j,ser);
						if(kk==1)/*0 表示什么也没有*/ 
							{
								tem2=temp;
								loc=find(i,j);
								swap(tem2.ch[loc.x][loc.y],tem2.ch[i][j]);
								if(temp.ch[i][j]=='W')tem2.stat=2;
								else tem2.stat=1;
								tem2.time++;
								if(bingo(tem2)){cout<<tem2.time;return;}
								tt=tem2;
								tt.time=0;
								tt.stat=0;
								if(S.count(tt)==0)
									{S.insert(tt);Q.push(tem2);}
							}
					}
     
		}while(!Q.empty());
}
int main()
{
	for(i=1;i<=4;++i)
		{
			cin>>s;
			for(j=1;j<=4;++j)
				st.ch[i][j]=s[j-1];
		}   
	BFS();
	return 0;
}
