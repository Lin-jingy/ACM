#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[2005];
int ans;
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=1;i<n;++i){
        for(int j=n-1;j>=i;--j){
            if(a[j]<a[j-1]){
                ans++;
                swap(a[j],a[j-1]);
            }
        }
    }
    cout<<ans;
    return 0;
}