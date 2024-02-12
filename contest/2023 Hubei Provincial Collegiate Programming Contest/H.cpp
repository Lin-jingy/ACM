// #include<bits/stdc++.h>

// using namespace std;
// #define int long long
// const int maxn=1e6+5,mod=998244353;
// int e[maxn];
// int cnt[70];
// void solve(){
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=m;i++){
//         int u,v;cin>>u>>v;
//         e[u]++;
//         e[v]++;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=60;j++){
//             if((e[i]>>j)&1)cnt[j]++;
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=60;j++){
//             if((e[i]>>j)&1){
//                 ans+=(n-cnt[j])*n%mod*cnt[j]%mod*(1LL<<j)%mod;
//                 ans%=mod;
//             }else{
//                 ans+=cnt[j]%mod*cnt[j]%mod*cnt[j]%mod*(1LL<<j)%mod;
//                 ans%=mod;
//             }
//         }
//     }
//     cout<<ans;
//     return ;
// }

// signed main(){
//     ios::sync_with_stdio(false),cin.tie(nullptr);
//     int t = 1;
//     //cin >> t;
//     while(t--)solve();
//     return 0;
// }

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long 
const int mod = 998244353;
int a[1000005];
unordered_map<int, int>mp;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int x, y;
    int ans = 0;
    while(m--){
        cin >> x >> y;
        a[x] ++, a[y] ++;
    }
    for(int i = 1; i <= n; ++ i)if(a[i] != 0)mp[a[i]]++;
    for(auto i : mp){
        for(auto j : mp){
            int x = i.first, y = j.first;
            if(x == y)continue;
            ans += (x ^ y) % mod * (x | y) % mod * (x & y)  % mod * i.second % mod * j.second % mod;
        }
    }
    cout << ans % mod * qpow(2, mod - 2) % mod;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}