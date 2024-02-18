#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &i:a) std::cin >> i;
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int ans = 1;
    for(int i = 0; i < a.size(); ++i) {
        int num = std::upper_bound(a.begin(), a.end(), a[i] + n - 1) - a.begin();
        ans = std::max(ans, num - i);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}