//DISJOINT SETS and KRUSKAL IMPLEMENTATION. 
//MINIMUM SPANNING TREE
//SPOJ MST

#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
struct edges
{
	ll x, y, weight;
} graph[200000];
struct subset{
	ll parent;
	ll rank;
} subsets[20000];

ll find(ll i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets[i].parent);	
	return subsets[i].parent;
}

void unions(ll x, ll y)
{
	ll xroot = find(x);
	ll yroot = find(y);

	if(subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot;
	else if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
bool comp(struct edges a, struct edges b)
{
	if(a.weight<b.weight)
		return true;
	return false;	
}
int N,M;
ll kruskal()
{
	sort(graph,graph+N,comp);
	for(int i=0;i<M;++i)
		subsets[i]={i,0};	
	ll ans=0;
	for(int i=0;i<N;++i)
		if(find(graph[i].x) != find(graph[i].y))
		{
			unions(graph[i].x,graph[i].y);
			ans+=graph[i].weight;
		}
	return ans;	
}
int main()
{
	cin>>M;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		ll x,y;
		cin>>x>>y>>graph[i].weight;
		graph[i].x=x-1;
		graph[i].y=y-1;
	}
	cout<<kruskal();
}