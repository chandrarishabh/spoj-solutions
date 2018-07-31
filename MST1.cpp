#include<bits/stdc++.h>
#define S(x) scanf("%d", &x)
using namespace std;
int dp[20000000+5];
/*int F(int N)
{
	if(A[N]!=-1)
		return A[N];
	if(N==1)
		return 0;
	if(N<1)
		return INT_MAX;
	int m1 = F(N-1)+1;
	int m2 = INT_MAX, m3 = INT_MAX;
	if(N%2==0)	m2 = F(N/2)+1;
	if(N%3==0)	m3 = F(N/3)+1;
	return A[N]  = min(m1,min(m2,m3));
}*/
int main()
{
	dp[1]=0, dp[2]=1;
	int t;
	scanf("%d",&t);
	for(int i=3;i<=20000000;++i)
		{
			int a=INT_MAX, b=INT_MAX, c=INT_MAX;
			a=dp[i-1]+1;
			if(i%2==0)	b=dp[i/2]+1;
			if(i%3==0)	c=dp[i/3]+1;
			dp[i]=min(a,min(b,c));
		}
	for(int i=1;i<=t;++i)
	{
		long N;
		S(N);
		printf("Case %d: %ld\n",i, dp[N]);
	}
}