#include<bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ll long long int
#define S(x) scanf("%d",&x);
using namespace std;
void driver(){
	int n;
	S(n);
	int ans=0;
	bool check=true;
	for(int i=0;i<n;++i)
	{
		int x;
		S(x);
		if(x!=1) check=false;
		ans^=x;
	}
	if(check)
	{
		if(n%2==0) cout<<"John\n";
		else cout<<"Brother\n";
		return;
	}
	if(ans==0) cout<<"Brother\n";
	else cout<<"John\n";	
}
int main()
{
	int t;
	S(t);
	while(t--)
	driver();
}