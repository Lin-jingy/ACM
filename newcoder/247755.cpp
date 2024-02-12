#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;++i)cin>>a[i];
        sort(a,a+n,greater<>());
        int ans=0;
        while(1){
            int k=1,flag=0;
            for(int i=ans;i<n;++i){
                flag=1;
                if(a[i]>=k)++k;
                else break;
            }
            if(!flag)break;
            --k;
            ans+=k;
            if(a[ans]==0)goto A;
        }
        A:;
        cout<<ans<<'\n';
    }
    return 0;
}