#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
struct info{
	int a;
	int b;
};
struct info data[1005];
bool comp(info x,info y)
{
	if(x.a < y.a)
		return true;
	else if(x.a == y.a)
		if(x.b<y.b)
			return true;
	return false;
}
int n;
int l[1000+5]={0};


int LIS[1000]={0};
int lis()
{
	LIS[0]=1;
	int ans=1;
	for(int i=1;i<n;++i)
	{
		LIS[i]=1;
		for(int j=0;j<i;++j)
			if(data[j].b<=data[i].b && LIS[i]<(LIS[j]+1))
				LIS[i]=1+LIS[j];
		if(ans<LIS[i]) ans=LIS[i];
	}
	return ans;
}

void driver()
{
	S(n);
	for(int i=0;i<n;++i)
		S(data[i].a);
	
	for(int i=0;i<n;++i)
		S(data[i].b);

	sort(data,data+n,comp);

	cout<<lis()<<endl;

}
int main()
{
	int t;
	S(t);
		while(t--)
			driver();
}