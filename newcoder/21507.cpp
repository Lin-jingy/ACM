#include<bits/stdc++.h>

#define int long long
const int mod = 100000007;
const int N = 2e5 + 5;
int p[N], rp[N];

int quickpow(int x, int y){
    int sum = 1;
    while(y){
        if(y & 1)sum = (sum * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return sum;
}

int rmod(int x){
    return quickpow(x, mod - 2);
}

int C(int x, int y){
    return (p[x] * rp[x - y] % mod * rp[y]) % mod;
}

void solve(){
    int n;
    std::cin >> n;
    //预处理
    p[0] = 1;
    p[1] = 1;
    for(int i = 2; i <= 2 * n; ++ i) p[i] = (p[i - 1] * i) % mod;
    rp[0] = 1;
    rp[1] = rmod(1);
    for(int i = 2; i <= 2 * n; ++ i) rp[i] = (rp[i - 1] * rmod(i)) % mod;
    //进行运算
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans += C(2 * i, i) - C(2 * i, i + 1) + mod;
        ans %= mod;
    }
    std::cout << ans;
}

signed main(){
    solve();
    return 0;
}