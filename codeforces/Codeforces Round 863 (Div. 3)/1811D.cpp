#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[50];


void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    while(n){
        if(y>=a[n]+1)y-=a[n];
        else if(y>a[n-1]){
            cout<<"NO\n";
            return;
        }
        --n;
        swap(x,y);
    }
    cout<<"YES\n";
}

signed main(){
    a[0]=1,a[1]=1;
    for(int i=2;i<=44;++i)a[i]=a[i-1]+a[i-2];
    int t;cin>>t;
    while(t--)solve();
    return 0;
}