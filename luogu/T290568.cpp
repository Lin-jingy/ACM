#include<bits/stdc++.h>
#define int long long 
#define X (1000000007) 
using namespace std;
int sum=0;
signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        sum=0;
        int n;
        cin>>n;
        int a[100005]={};
        for(int j=1;j<=n;++j){
            cin>>a[j];
        }
        for(int w1=1;w1<=n;++w1){
            for(int w2=1;w2<=n;++w2){
                for(int w3=1;w3<=n;++w3){
                    sum+=((a[w1]&a[w2])%X)*((a[w2]|a[w3])%X)% X;
                }
            }
        }
        cout<<sum%X<<'\n';
    }
    return 0;
}