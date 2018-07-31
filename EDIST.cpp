#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int dp[2005][2005]={0};

void driver()
{
	string a, b;
	cin>>a>>b;
	int A=a.length(), B=b.length();
	
	for(int i=0;i<=A;++i)
		for(int j=0;j<=B;++j)
		{
			if(i==0&&j==0) dp[i][j]=0;
			else if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}

	cout<<dp[A][B]<<endl;
}
int main()
{
	int t;
	S(t);
	while(t--) driver();
}