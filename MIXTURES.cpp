#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int store[105]={0};
int sum[105]={0};

int dp[105][105];

void driver(int n)
{
	for(int i=1;i<=n;++i)
	{
		cin>>store[i];
		sum[i]=(sum[i-1]+store[i]);
	}

	for(int j=1;j<=n;++j)
		for(int i=j;i>=1;--i)
		{
			if(i==j) dp[i][j]=0;
			else
			{
				dp[i][j]=INT_MAX;
				for(int k=i;k<j;++k)
				{
					int lc = (sum[k]-sum[i-1])%100;
					int rc = (sum[j]-sum[k])%100;
					dp[i][j]=min(dp[i][j], (lc*rc)+dp[i][k]+dp[k+1][j] );
				}
			}
		}

/*	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<dp[1][n]<<endl;
}	
int main()
{
	int t;
	while(cin>>t)
		driver(t);
}