#include<bits/stdc++.h>
#define int long long 
signed main(){
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int t;std::cin>>t;
    while(t--){
        int n;std::cin>>n;
        std::string a;
        std::cin>>a;
        std::deque<int>q;
        for(auto i:a)q.push_back(i-'0');
        while(!q.empty()){
            if(q.front()+q.back()==1)q.pop_front(),q.pop_back();
            else break;
        }
        std::cout<<q.size()<<'\n';
    }
    return 0;
}