#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string x;
        int sum=0;
        for(int i=0;i<n*n-1;++i){
            cin>>x;
            for(int j=0;j<4;++j){
                if(x[j]=='1')sum--;
                else if(x[j]=='2')sum++;
            }
        }
        cout<<-sum+10<<'\n';
    }
    return 0;
}