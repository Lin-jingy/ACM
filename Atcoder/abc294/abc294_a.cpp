#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main(){
    quick;
    int n;cin>>n;
    int x;
    while(n--){
        cin>>x;
        if(x%2==0)cout<<x<<' ';
    }

    return 0;
}