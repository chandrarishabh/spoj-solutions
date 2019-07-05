#include <bits/stdc++.h>
#define ll long long
#define S(x) scanf("%d",&x)
#define debug(x) cout<<#x<<'='<<x<<endl;
using namespace std;

int binarySearch(vector<int> A, int target){
    int low = 0, high=A.size()-1, mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(target<=A[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    if(low<A.size() && A[low] == target) return low;
    else return -1;
}

int main()
{
	while(1){
		int n,m;
		cin>>n;
		if(n==0) return 0;
		vector<int> A(n);
		vector<ll> prefixA;
		for(int i=0;i<n;++i){
			cin>>A[i];
		}
		//sort(A.begin(),A.end());
		for(int i=0;i<n;++i){
			prefixA.push_back(A[i]+(i==0?0:prefixA[i-1]));
		}
		cin>>m;
		vector<int> B(m);
		vector<ll> prefixB;
		for(int i=0;i<m;++i){
			cin>>B[i];
		}
		//sort(B.begin(),B.end());
		for(int i=0;i<m;++i){
			prefixB.push_back(B[i]+ (i==0?0:prefixB[i-1]));
		}
		//debug("hello");
		ll ans=0;
		int pa,pb,firstime=0; 
		for(int i=0;i<n;++i){
			int tpx = binarySearch(B,A[i]);
		//	debug(i);
		//	debug(tpx);
			if(tpx==-1) continue;
			else{
				if(!firstime){
					firstime=1;
					pa=i;
					pb=tpx;
					ans += max(prefixA[pa],prefixB[pb]);
				}else{
					ans += max(prefixA[i]-prefixA[pa],prefixB[tpx]-prefixB[pb]);
					pa=i,pb=tpx;
				}
			}
		}
		if(firstime) ans += max(prefixA[n-1]-prefixA[pa],prefixB[m-1]-prefixB[pb]);
		else ans += max(prefixA[n-1],prefixB[m-1]);
		cout<<ans<<endl;
	}		
	return 0;
}