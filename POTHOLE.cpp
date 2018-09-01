//FORD_FULKERSON MAX FLOW
#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;

using namespace std;
int n,m;
int graph[1000][1000]={0};
int paths[1000][1000]={0};
int parent[1000] = {0};
bool findpath(int s, int t)
{
	bool visited[1000];
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s]=true;
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
        if(top == t ) break;
		for(int i=1;i<=n;++i)
		{
			if(paths[top][i]>0 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
				parent[i]=top;
			}
		}
	}
	return (visited[t]==true) ;
}

int ford(int s,int t)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			paths[i][j]=graph[i][j];
    int maxflow = 0;
 //   debug("hello2");
	while(findpath(s,t))
	{
   //     debug("hello3");
		int minpath=INT_MAX;
		for(int i=t;i!=s;i=parent[i])
		{
			int u = parent[i];
			minpath = min(minpath,paths[u][i]);
		}
		for(int i=t;i!=s;i=parent[i])
		{
			int u = parent[i];
			paths[u][i] -= minpath;
			paths[i][u] += minpath;
		}
		maxflow += minpath;
	}
	return maxflow;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(graph,0,sizeof(graph));
		memset(paths,0,sizeof(paths));
		memset(parent,0,sizeof(parent));
		cin>>n;
		for(int i=1;i<=n-1;++i)
		{
			cin>>m;
			for(int j=0;j<m;++j)
			{
				int t;
				cin>>t;
				graph[i][t]=(i==1||t==n)?1:1000000;
			}
		}
        //debug("hello");
		cout<<ford(1,n)<<endl;
	}
}	