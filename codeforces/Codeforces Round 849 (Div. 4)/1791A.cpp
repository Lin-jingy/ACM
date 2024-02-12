#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        char a;cin>>a;
        if(a=='c' or a=='o' or a=='d' or a=='e' or a=='f' or a=='r' or a=='s')cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}