// #include<bits/stdc++.h>

// using namespace std;
// #define int long long
// int a, x, mod;

// int qpow(int a, int b,int p){
//     int sum = 1;
//     while(b){
//         if(b & 1)sum = sum * a % p;
//         b >>= 1;
//         a = a * a % p;
//     }
//     return sum;
// }


// void solve(){
//     cin >> a >> x >> mod;
//     //(a1 * (1 - q^n)) / (1 - q)
//     //cout << (qpow(a, x, mod * (a - 1)) - 1) / (a - 1);
//     if(a == 1){
//         cout << x;
//         return;
//     }
//     if(__gcd(a - 1, mod) == 1)cout << abs(-(1 - qpow(a, x, mod)) * qpow(a - 1, mod - 2, mod) % mod);
//     else cout << abs(-(1 - qpow(a, x, (a - 1) * mod)) / (a - 1));
// }

// signed main(){
//     std::ios::sync_with_stdio(false),cin.tie(nullptr);
//     int t = 1;
//     //cin >> t;
//     while(t--)solve();
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, x, mod;

int qpow(int a, int b){
    a %= mod;
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

int sum(int a,int b){
    if(b == 0) return 1;
    if(b & 1) return (sum(a, b / 2) % mod * (qpow(a, b / 2 + 1) + 1)) % mod;
    else return (sum(a, b - 1) % mod + qpow(a, b)) % mod;
}

void solve(){
    cin >> a >> x >> mod;
    if(mod == 1)cout << 0;
    else cout << sum(a, x - 1) % mod;
}

signed main(){
    std::ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}