#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    int x=0;
    for(int i=0;i<t;++i){
        cin>>x;
        double a=log2(x);
        int aa=log2(x);
        if(a==aa)cout<<aa<<'\n';
        else cout<<aa+1<<'\n';
    }
    return 0;
}