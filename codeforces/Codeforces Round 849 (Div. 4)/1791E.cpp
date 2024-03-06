
#include<bits/stdc++.h>
#define int long long 
int a[200005];
signed main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int t;std::cin>>t;
    while(t--){
        int n;std::cin>>n;
        for(int i=0;i<n;++i)std::cin>>a[i];
        int sum=0;
        int k=0;
        for(int i=0;i<n;++i)if(a[i]<0)++k;
        if(k%2==0){
            for(int i=0;i<n;++i)sum+=abs(a[i]);
            std::cout<<sum<<'\n';
        }else{
            int min=INT_MAX;
            for(int i=0;i<n;++i)min=std::min(min,abs(a[i]));
            for(int i=0;i<n;++i)sum+=abs(a[i]);
            std::cout<<sum-2*min<<'\n';
        }
    }
    return 0;
}