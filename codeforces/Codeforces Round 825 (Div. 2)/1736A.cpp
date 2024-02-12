#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < n; ++i) std::cin >> b[i];
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i) if(a[i] == b[i]) ++sum;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        if(a[i] == b[i]) --sum;
        else ++ans;
    }
    if(sum != 0) ++ans;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
