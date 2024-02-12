#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 998244353;
const int N = 2e6 + 5;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
inline int rmod(int a){return qpow(a, mod - 2);} 
int a[N], ra[N];

void solve(){
    int n;
    while(cin >> n){
        cout << a[n] * a[n] % mod * ra[2 * n + 1] % mod << '\n';
    }
}

signed main(){
    a[1] = 1, ra[1] = rmod(1);
    for(int i = 2; i < N; ++ i){
        a[i] = a[i - 1] * i % mod;
        ra[i] = rmod(a[i]);
    }
    solve();
    return 0;
}