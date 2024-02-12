#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>p;
int MAX=INT_MAX;
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;char pd;
        cin>>x>>pd;
        if(pd=='.'){p[x]++;p[x+1]--;}
        else if(pd=='-'){p[x+1]++;}
        else if(pd=='+'){p[x]--;p[0]++;}
    }
    int ans=0,t=0;
    while(!p.empty()){
        t+=p.begin()->second;
        if(t>ans){
            ans=t;
        }
        p.erase(p.begin());
    }
    cout<<ans;
    return 0;
}