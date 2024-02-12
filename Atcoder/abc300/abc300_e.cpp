#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long 
using PII = pair<int, int>;

const int mod = 998244353;
int n, ans = 0;
unordered_map<int, int>mp;

int qpow(int a, int b) {
    int sum = 1;
    while (b) {
        if (b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
#define rmod(x) qpow(x, mod - 2)

//int dfs(int x, int k) {
//    if (x == 1) {
//        ans = ans + rmod(k) % mod;
//        return rmod(k);
//    }
//    else if (mp.count(x)) {
//        ans = ans + rmod(k) * mp[x] % mod;
//        return rmod(k) * mp[x] % mod;
//    }
//    else {
//        int sx = 0;
//        for (int i = 2; i <= 6; ++i)if (x % i == 0)sx = sx + dfs(x / i, k * 5) % mod;
//        return mp[x] = sx;
//    }
//}

int dfs(int x) {
    if (x > n)return 0;
    else if (x == n)return 1;
    else if (mp.count(x))return mp[x];
    int sum = 0;
    for (int i = 2; i <= 6; ++i)sum += dfs(i * x);
    sum = sum * rmod(5) % mod;
    mp[x] = sum;
    return sum;
}


void solve() {
    cin >> n;
    cout << dfs(1) % mod;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t--)solve();
    return 0;
}
