#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>a;
    int x;
    for(int i=0;i<2*n;++i){
        cin>>x;
        a.emplace_back(x);
    }
    if(n==1)cout<<abs(a[0]-a[1])<<"\n";
    else{
        int k1=0;
        sort(a.begin(),a.end());
        for(int i=0;i<2*n;++i)k1+=abs(a[i]);
        if(n%2==1)cout<<k1<<'\n';
        else {
            int k2=0,k3=0;
            for(int i=0;i<2*n-1;++i)k2+=abs(a[i]+1);
            k2+=abs(a[2*n-1]-n);
            if(n==2){
                for(int i=0;i<2*n;++i)k3+=abs(a[i]-2);
                cout<<min(k1,min(k2,k3))<<'\n';
            }else cout<<min(k1,k2)<<'\n';
        }
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}