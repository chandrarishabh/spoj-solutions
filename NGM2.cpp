#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
int A[20]={0};
ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	ll n, k,ans;
	cin>>n>>k;
	ans=n;
	for(ll i=0;i<k;++i)
		cin>>A[i];
	for(ll i=1;i<(1<<k);++i)
	{
		ll x=1,y=0;
		for(ll j=0;j<k;++j){
			if(i&(1<<j))
			{
				x = lcm(A[j],x);
				y++;
			}
		}
		if(y&1)
			ans -= n/x;
		else ans +=n/x;
	}
	cout<<ans;
}