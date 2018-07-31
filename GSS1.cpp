#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
ll ar[500000];
ll n;
struct info{
	ll prefix;
	ll suffix;
	ll total;
	ll best;
} tree[5000000]={0,0,0,0};
void build(int node, int a, int b)
{
	if(a==b)
	{
		tree[node].prefix = ar[a];
		tree[node].suffix = ar[a];
		tree[node].total = ar[a];
		tree[node].best = ar[a];
	}
	else
	{
		int mid=(a+b)/2;
		build(2*node,a,mid);
		build(2*node+1,mid+1,b);
		info a = tree[2*node], b = tree[2*node+1];
		tree[node].prefix = max(a.total+b.prefix, a.prefix);
		tree[node].suffix = max(a.suffix+b.total, b.suffix);
		tree[node].total = a.total + b.total;
		tree[node].best = max(a.suffix+b.prefix, max(a.best,b.best));
	}
}

struct info query(int node, int a, int b, int i, int j)
{
	if(b<i || j<a || a>b){
		struct info temp={INT_MIN,INT_MIN,INT_MIN,INT_MIN};
		return temp;
	}
	if(i<=a&&b<=j) return tree[node];
	int mid=(a+b)/2;
	info ql = query(2*node,a,mid,i,j);
	info qr = query(2*node+1,mid+1,b,i,j);
	struct info ans;
	ans.prefix=max(ql.total+qr.prefix,ql.prefix),
	ans.suffix=max(ql.suffix+qr.total, qr.suffix), ans.total=ql.total+qr.total;
	ans.best=max(ql.suffix+qr.prefix, max(ql.best,qr.best));
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>ar[i];
	int q;
	cin>>q;
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<query(1,1,n,x,y).best<<endl;
	}
}