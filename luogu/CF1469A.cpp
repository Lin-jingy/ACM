#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    string a;
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>a;
        if(a.size()%2==1 || a[0]==')' || a[a.size()-1]=='(')cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    } 
    return 0;
}