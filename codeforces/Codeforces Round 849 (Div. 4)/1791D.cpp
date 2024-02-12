#include<bits/stdc++.h>
#define int long long
signed main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int t;std::cin>>t;
    while(t--){
        int pd1[26]={0},pd2[26]={0};
        int n;std::cin>>n;
        std::string a;
        std::cin>>a;
        int f1=0,f2=0,ans=0;
        for(auto i:a)pd2[i-'a']++;
        for(int i=0;i<26;++i)if(pd2[i])++f2;
        for(int i=0;i<n;++i){
            pd2[a[i]-'a']--;
            if(!pd2[a[i]-'a'])--f2;
            if(!pd1[a[i]-'a'])pd1[a[i]-'a']++,f1++;
            ans=std::max(ans,f1+f2);
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}