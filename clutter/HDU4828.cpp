#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int mod = 1000000007;
const int N = 2e6 + 5;
int p[N];
int flag = 1;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
#define rmod(x) qpow(x, mod - 2)

void solve(){
    int n;
    cin >> n;
    cout << "Case #" << flag ++ << ":\n";
    cout << p[2 * n] * rmod(p[n + 1]) % mod * rmod(p[n]) % mod << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    p[0] = 1;
    for(int i = 1; i < N; i++)p[i] = p[i - 1] * i % mod;
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
