#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int x){
    int sum=0;
    while(x){
        int k=x%10;
        if(k==2 || k==0 || k==1 || k==9)return true;
        x/=10;
    }
    return false;
} 
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i){
        if(check(i))ans+=i;
    }
    cout<<ans;
    return 0;
}