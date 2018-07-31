#include <bits/stdc++.h>
#define ll long long
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define debug(x) cout<<#x<<'='<<x<<endl;
using namespace std;
bool tasks[20+5][20+5];
ll dp[(1<<21)];
int n;
ll rec(int mask, int x)
{
	if(dp[mask]==-1)
	{
		int per=0;
		for(int k=0;k<n;++k)
			if(mask&(1<<k))
				per++;
		//base case
		if(mask==x)
			return 1LL;
		//recursive case
		ll ans=0LL;
		for(int a=0;a<n;++a)
		{
			if(!tasks[per][a])
				continue;
			if(mask&(1<<a))	continue;
			int new_mask = mask|(1<<a);
			ans+=rec(new_mask,x); 
		}
		return dp[mask]=ans;
	}
	return dp[mask];
}
void driver()
{
	memset(dp,-1,sizeof(dp));
	memset(tasks,false,sizeof(tasks));
	S(n);
	int x = (1<<n)-1;
	for(int person=0;person<n;++person)
	{
		for(int assigns=0;assigns<n;++assigns)
		{
			int temp;
			scanf("%d",&temp);
			tasks[person][assigns]=temp;
		}
	}
	printf("%lld\n",rec(0,x));
	
}
int main()
{
	int t;
	S(t);
	while(t--)
	{
		driver();
	}	
}