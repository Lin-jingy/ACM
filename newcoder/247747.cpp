#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
vector<int>v;
auto f(int x){
    return round(10*sqrt(x));
}
signed main(){
    quick;
    int n,m;cin>>n>>m;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        v.emplace_back(x);
    }
    int op,l,r,k;
    for(int i=0;i<m;++i){
        cin>>op;
        if(op==1){
            cin>>l>>r>>k;
            
        }
    }
    return 0;
}