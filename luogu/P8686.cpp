#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
map<int,int>s;
signed main(){
    quick;
    int n;cin>>n;
    int x;
    for(int i=1;i<=1000000;++i)s[i]=0;
    for(int i=0;i<n;++i){
        cin>>x;
        if(s.count(x)){
            s.erase(s.find(x));
            cout<<x<<' ';
        }else{
            auto it=s.upper_bound(x);
            cout<<it->first<<' ';
            s.erase(it);
        }
    }
    return 0;
}