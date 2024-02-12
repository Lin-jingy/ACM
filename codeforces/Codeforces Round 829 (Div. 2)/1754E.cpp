//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int mod = 998244353;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int k = count(a.begin(), a.end(), 0);
    int sk = count(a.begin(), a.begin() + k, 1);
    int ans = 0;
    for(int i = 1; i <= sk; ++i){
        ans = (ans + n * (n - 1) % mod * qpow(i * i * 2 % mod, mod - 2) % mod) % mod;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
