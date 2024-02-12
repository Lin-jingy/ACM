#include<bits/stdc++.h>
#define int long long
signed main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int t;std::cin>>t;
    while(t--){
        int n;std::cin>>n;
        std::string a;
        std::cin>>a;
        int x=0,y=0;
        int flag=0;
        for(auto i:a){
            if(i=='L')--x;
            else if(i=='R')++x;
            else if(i=='U')++y;
            else if(i=='D')--y;
            if(x==1 and y==1)flag=1;
        }
        if(flag)std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
    return 0;
}