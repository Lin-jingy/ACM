#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 10;
int a[N], vis[N];
vector<int>v;

void fact(){
    for(int i = 2; i < N; ++i){
        if(vis[i])continue;
        v.emplace_back(i);
        for(int j = i; j < N; ++j)vis[j] = 1;
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    sort(a + 1, a + 1 + n);
    fact();
    int flag = 0;
    for(int i = 1; i <= n; ++i){
        while(v[flag] < a[i])flag++;
        cout << v[flag] << ' ';
        ++flag;
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
