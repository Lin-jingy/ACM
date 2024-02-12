#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod=1e9 + 9;
string s;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

signed main(){
    int n, a, b, k;
    cin >> n >> a >> b >> k >> s;
    int res=0;
    for(int i = 0; i < s.size(); ++i){
        int flag;
        s[i] == '+' ? flag = 1 : flag = -1;
        res=((res + flag * qpow(a, n-i) * qpow(b, i))% mod + mod) % mod;
    }
    int t = qpow(b, k) * qpow(a, k * (mod - 2)) % mod;
    if (t == 1) res = res * ((n + 1) / k) % mod;
    else res = res * (qpow(t, (n + 1) / k) - 1) % mod * qpow(t - 1, mod - 2) % mod;
    cout << res;
    return 0;
}