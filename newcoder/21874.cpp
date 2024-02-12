#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string a;
    cin>>a;
    int len = a.size();
    int k=0;
    for(int i=0;i<len;++i){
        if(a[i]=='a')++k;
        else if(a[i]=='b')--k;
        if(k<0){cout<<"Bad";return 0;}
    }
    if(k==0)cout<<"Good";
    else cout<<"Bad";
    return 0;
}