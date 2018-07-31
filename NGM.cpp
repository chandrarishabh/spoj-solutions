#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int main()
{
	ll n;
	cin>>n;
	if(n%10==0)
		cout<<2<<'\n';
	else
		cout<<1<<'\n'<<n%10;
}