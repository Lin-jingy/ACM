#include<bits/stdc++.h>

using namespace std;
#define int long long 
int a[200005], p[200005];
vector<int>v;

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    for(int i = 1; i <= n; ++ i){
        if(!p[i])p[a[i]] = 1;
    }
    for(int i = 1; i <= n;++ i)if(p[i] == 0)v.push_back(i);
    cout << v.size() << '\n';
    for(auto i : v)cout << i << ' ';
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();
    return 0;
}