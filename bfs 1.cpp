#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int stime[100],etime[100],t=0,count=0,rm,vt[100],apl=0;
int adj[100][100],color[100],vertex;
int hasApple[100];

void dfsvisit(int x)
{
	color[x]=GRAY;
//	cout<<x<<endl;

	for(int i=0;i<vertex;i++)
	{
		
		if(adj[x][i]==1)
		{
			if(color[i]==WHITE)
			{
				t++;
				vt[i]=t;
				dfsvisit(i);
			}
		}
	}
	if(hasApple[x]==1) {
		node=x;
		value+=1;
		cout<<x<<" x"<<endl;
	}
	t--;
//	cout<<x<<" "<<vt[x]<<endl;
	color[x]=BLACK;
	
}

void dfs()
{
	for(int i=0;i<vertex;i++)
	color[i]= WHITE;
	for(int i=0;i<vertex;i++)
	{
		if(color[i]==WHITE)
		{
			dfsvisit(i);
		}
	}
}

int main()
{
	freopen("tst.txt","r", stdin);
	cin>>vertex;
	
	for(int i=1;i<vertex;i++)
	{
		int n1,n2;
		cin>>n1>>n2;
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	for(int i=0;i<vertex;i++)
	{
		cin>>hasApple[i];
		if(hasApple[i]==1)
		apl++;
	}
	cout<<apl;
	dfs();
	return 0;
}
