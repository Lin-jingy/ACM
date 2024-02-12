#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int,vector<int>,greater<>>a;
set<int>s;
void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        a.push(i);
    }
    int x;
    while(q--){
        cin>>x;
        if(x==1){
            s.insert(a.top());
            a.pop();
        }else if(x==2){
            cin>>x;
            s.erase(s.find(x));
        }else{
            cout<<*s.begin()<<'\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;
    while(t--)solve();
    return 0;
}