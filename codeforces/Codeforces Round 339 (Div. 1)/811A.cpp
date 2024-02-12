#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a,b;cin>>a>>b;
    for(int i=1;;++i){
        if(i%2==1)a-=i;
        else b-=i;
        if(b<0){cout<<"Valera";return;}
        if(a<0){cout<<"Vladik";return;}
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}