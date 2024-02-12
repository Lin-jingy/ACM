#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

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
    int c = qpow(6, mod - 2);
    while(cin >> n){
        n %= mod;
        cout << n * (n + 1) % mod * (2 * n + 1) % mod * c % mod << '\n';
    }
}

signed main(){
    solve();
    return 0;
}