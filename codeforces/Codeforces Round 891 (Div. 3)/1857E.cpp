#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i], b[i] = a[i];
    std::sort(a.begin(), a.end());
    std::map<int, long long> mp;
    long long ans = 0;
    for(int i = 0; i < n; ++i) ans += a[i] - a[0] + 1;
    mp[a[0]] = ans;
    int l = 1, r = n - 1;
    for(int i = 1; i < n; ++i, ++l, --r) {
        ans += (1ll * a[i] - a[i - 1]) * l;
        ans -= (1ll * a[i] - a[i - 1]) * r;
        mp[a[i]] = ans;
    }
    for(int i = 0; i < n; ++i) std::cout << mp[b[i]] << " \n"[i == n - 1];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}