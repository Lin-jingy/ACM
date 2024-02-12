#include<bits/stdc++.h>
using namespace std;
#define int long long 
priority_queue<pair<int,int>>q;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;cin>>n>>k;
    int x;
    for(int i=1;i<=n;++i){
        cin>>x;
        q.push({x,i});
        while(q.top().second<=i-k)q.pop();  
        if(i>=k)cout<<q.top().first<<'\n';
    }

    return 0;
}