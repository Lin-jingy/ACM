#include<bits/stdc++.h>

#define int long long
const int N = 2e5 + 5;
const int mod = 998244353;
int fac[N], inv[N];


void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> a;
    a.emplace_back(1);
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == s[i - 1]) a.back()++;
        else a.emplace_back(1);
    }
    int ans1 = 0, ans2 = 1;
    for(int i = 0; i < a.size(); i ++) {
        ans1 += a[i] - 1;
        ans2 = ans2 * a[i] % mod;
    }
    for(int i = 1; i <= ans1; i++) ans2 = ans2 * i % mod;
    std::cout << ans1 << ' ' << ans2 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;

    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}