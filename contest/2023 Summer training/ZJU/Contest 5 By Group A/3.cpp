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

const int mod = 1e9 + 7;
const int N = 1e6 + 6;
int a[N];
int p[N], rp[N];
int n, k;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

int C(int x, int y){ //C x 取 y
    if(y > x or x == 0) return 0;
    y = min(y, x - y);
    if(y == 0)return 1;
    return p[x] * rp[y] % mod * rp[x - y] % mod;
}

void solve(){
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    sum = sum % mod * C(n - 1, k) % mod;
    int kk = 0;
    for(int i = 2; i <= n; ++i) kk = (kk + (2 * a[i] * k % mod)) % mod;
    int ans = (sum - kk + mod) % mod;
    ans = ans * qpow(C(n - 1, k), mod - 2) % mod;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    p[1] = 1, rp[1] = 1;
    for(int i = 2; i < N; ++i) {
        p[i] = p[i - 1] * i % mod;
        rp[i] = qpow(p[i], mod - 2);
    }
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
