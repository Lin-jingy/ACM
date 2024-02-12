#include<bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    long long l = 1, r = 1e15;
    auto check = [&](long long mid) -> bool {
        __int128 sum = 0;
        for(auto i:a) sum += (i <= mid ? mid - i : 0);
        return sum <= x;
    };
    long long ans = 0;
    while(l <= r) {
        long long mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
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