#include<iostream>
#include<stack>

using namespace std;
#define int long long
stack<int>s;

void solve() {
    int n,x,ans=0;
    cin>>n;
    while(n--){
        cin>>x;
        while(!s.empty() and s.top()<=x)s.pop();
        ans+=s.size();
        s.push(x);
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}