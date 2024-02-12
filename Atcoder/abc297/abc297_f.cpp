#include<bits/stdc++.h>

#define int long long
const int mod = 998244353;
const int N = 2e6 + 5;
int p[N], rp[N];
int h, w, k, ans = 0;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = (sum * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return sum;
}

inline int rmod(int a){
    return qpow(a, mod - 2);
}

inline int C(int a, int b){
	if(a < b)return 0;
    return p[a] * rp[b] % mod * rp[a - b] % mod;
}

int sum(int i, int j){
    return C(i*j, k)%mod - 2*C((i-1)*j, k)%mod - 2*C(i*(j-1), k)%mod + 4*C((i-1)*(j-1), k)%mod + 
    C((i-2)*j, k)%mod + C(i*(j-2), k)%mod - 2*C((i-2)*(j-1), k)%mod - 2*C((i-1)*(j-2), k)%mod + C((i-2)*(j-2), k)%mod;
}

void solve(){
    std::cin >> h >> w >> k;
	if(k == 1){
		std::cout << 1;
		return;
	}
    for(int i = 1; i <= h; ++ i){
        for(int j = 1; j <= w; ++ j){
			if(i * j < k)continue;
            ans = (ans + (sum(i, j) + mod) % mod * i % mod * j % mod * (h - i + 1) % mod * (w - j + 1)) % mod;
        }
    }
    std::cout << ans * rmod(C(h * w, k)) % mod;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //预处理
    p[0] = 1, rp[0] = 1;
    for(int i = 1; i < N; ++ i){
		p[i] = p[i - 1] * i % mod;
		rp[i] = rmod(p[i]) % mod;
	}
    solve();
    return 0;
}