#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main(){
    quick;
    int n,m;cin>>n>>m;
    int x;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>x;
            if(x==0)cout<<'.';
            else cout<<(char)(x+'A'-1);
        }
        cout<<'\n';
    }

    return 0;
}