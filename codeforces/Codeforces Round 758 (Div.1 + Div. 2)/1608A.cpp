#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
// const int N = 1e6;
// int vis[N];
// vector<int>v;

// void fact(){
//     for(int i = 2; i < N; ++ i){
//         if(vis[i])continue;
//         v.push_back(i);
//         for(int j = i; j < N; j += i)vis[j] = 1;
//     }
// }

// void solve(){
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; ++ i)cout << v[i] << ' ';
//     cout << '\n';

// }

void solve(){
    int n;cin >> n;
    for(int i = 2; i <= n + 1; ++ i)cout << i << " \n"[i == n + 1];
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    //fact();
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
