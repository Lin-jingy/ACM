#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int  mod = 100000007;
int a[100000], p[100005];

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
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    int k = p[n - 1] * n % mod * qpow(2, mod - 2) % mod * (n - 1) % mod + p[n - 1] % mod;
    //cout << k << '\n';
    for(int i = 1; i <= n; ++ i)ans = ans + a[i] * k % mod;
    ans = ans * qpow(n * (n - 1) % mod, mod - 2) % mod; 
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    p[1] = 1;
    for(int i = 2; i <= 100000; ++ i)p[i] = p[i - 1] * i % mod;
    //cin >> t;
    while(t--)solve();
    return 0;
}
