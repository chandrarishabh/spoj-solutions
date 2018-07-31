#include<bits/stdc++.h>
using namespace std;

bool F(int n,int C, vector<int> s)
{
    int placed = 1, last = s[0];
    for(auto i:s)
    {
        if(i-last>=n)
        {
            last=i;
            placed++;
            if(placed==C) return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    vector<int> s;
    int N,C;
    cin>>N>>C;
    for(int i=0;i<N;i++)
    {
        int p;
        cin>>p;
        s.push_back(p);
    }
    sort(s.begin(),s.end());
    int lD = 0, hD=s[N-1]-s[0], mid;
    while(hD>=lD)
    {
        mid=lD+((hD-lD)/2);
        if(F(mid,C,s))
            lD=mid+1;
        else
            hD=mid-1;
    }
    cout<<lD-1<<endl;
    }

}
