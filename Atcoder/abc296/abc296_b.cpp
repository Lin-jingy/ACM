#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    char x;
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            cin>>x;
            if(x=='*'){
                cout<<(char)(j+'a'-1);
                cout<<8-i+1;
                return;
            }
        }
    }


}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    solve();
    return 0;
}