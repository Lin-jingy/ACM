// #include<bits/stdc++.h>

// using namespace std;
// #define int long long 
// using PII = pair<int, int>;
// const int mod = 1e9 + 7;
// const int N = 5e4 + 5;
// int p[N], rp[N];
// #define rmod(x) qpow(x, mod - 2);
// int C(int a, int b){//C a取b
//     b = min(b, a - b);
//     if(b > a)return 0;
//     if(a == b or b == 0)return 1;
//     return p[a] * rp[b] % mod * rp[a - b] % mod;
// }

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     if(n > m) swap(n, m);
//     if(n == 1){
//         std::cout << m << '\n';
//         return ;
//     }
//     int ans = 0;
//     for(int i = 1; i <= n; ++i)
//         ans += C(n, i);
//         ans %= mod;
//     }
//     ans = qpow(ans, m);
//     std::cout << (ans + mod - n) % mod << '\n';
// }

// signed main(){
//     ios::sync_with_stdio(0), cin.tie(0);
//     p[1] = rp[1] = 1;
//     for(int i = 2; i < N; ++i){
//         p[i] = p[i - 1] * i % mod;
//         rp[i] = rmod(p[i]);
//     }
//     int _;
//     cin >> _;
//     while(_--)solve();
//     return 0;
// }