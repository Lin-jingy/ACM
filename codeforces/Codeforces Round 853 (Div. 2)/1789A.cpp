#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>a;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;
        a.clear();
        for(int i=0;i<n;++i){cin>>x;a.emplace_back(x);}
        for(auto i:a){
            for(auto j:a){
                if(__gcd(i,j)<=2){cout<<"yes\n";goto A;}
            }
        }
        cout<<"no\n";
        A:;
    }
    return 0;
}