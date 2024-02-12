#include<bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), h(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= n; ++i) std::cin >> h[i];
    if(n == 1) {
        if(a[1] > k) std::cout << 0 << '\n';
        else std::cout << 1 << '\n';
        return;
    }
    bool flag = false;
    for(int i = 1; i <= n; ++i) if(a[i] <= k) flag = true;
    if(!flag) {
        std::cout << 0 << '\n';
        return ;
    }
    int ans = 0;
    long long sum = a[1];
    int l = 1, r = 1;
    while(1) {
        ans = std::max(r - l + 1, ans);
        if(h[r] % h[r + 1] == 0 and sum + a[r + 1] <= k) ++r, sum += a[r];
        else sum -= a[l], ++l;
        if(l > r) ++r, sum += a[r], l = r;
        ans = std::max(r - l + 1, ans);
        if(r == n) break;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}