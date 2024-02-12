#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 998244353;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

int rmod(int x) {return qpow(x, mod - 2);}

void solve(){
    int x = 2;
    int y = 3;
    cout << (x ^ y) * (x | y) * (x & y);

    
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
/* 
! 14/25
*/