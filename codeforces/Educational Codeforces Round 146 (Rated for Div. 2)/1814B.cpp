#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int a, b;
    cin >> a >> b;
    int sum = a+b;
    int ans = INT_MAX;
    if(a > b)swap( a , b );
    for(int i = 1; i <= min( 1000000ll, sum ); ++i){
        int mid = i + b / i - 1;
        if(b % i != 0)++mid;
        mid += a / i;
        if(a % i != 0)++mid;
        ans=min(ans,mid);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t; cin>>t;
    while(t--)solve();
    return 0;
}