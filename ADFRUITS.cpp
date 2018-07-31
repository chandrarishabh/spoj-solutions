#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
char a[105],b[105];
int dp[105][105]={0};
void print(string a, string b)
{
	int A=a.length(), B=b.length();
	for(int i=0;i<=A;++i)
		for(int j=0;j<=B;++j)
		{
			if(i==0||j==0) dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	int lcs = dp[A][B];
	char common[lcs];
	int i=A, j=B, w=lcs-1;
	while(i&&j)
	{
		if(a[i-1]==b[j-1])
		{
			common[w]=a[i-1];
			i--;
			j--;
			w--;
			if(w==-1) break;
		}
		else if(dp[i-1][j] < dp[i][j-1] ) j--;
		else i--;
	}

	i=0, j=0;
	int k=0;
	while(i<A||j<B)
	{
		if(i>=A && j>=B) break;
		else if(i>=A)
		{
			cout<<b[j];
			j++;
		}
		else if(j>=B)
		{
			cout<<a[i];
			i++;
		}
		else if(a[i]==b[j] && b[j]==common[k])
		{
			cout<<a[i];
			i++;
			j++;
			k++;
		}
		else if(a[i]==common[k] && b[j]!=common[k])
		{
			cout<<b[j];
			j++;
		}
		else/* if(a[i]!=common[k] && b[j]==common[k])*/
		{
			cout<<a[i];
			i++;
		}
	}
	cout<<endl;
}

int main()
{
	string a,b;
	while(cin>>a)
	{
		cin>>b;
		print(a,b);
	}
	
    return 0;
}