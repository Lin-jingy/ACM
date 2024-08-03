#include <bits/stdc++.h>
void solve();
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
#define int long long
constexpr std::vector<int> Init(int n) {
    std::vector<int> u(n + 1), prime;
    std::vector<bool> vis(n + 1);
    u[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            u[i] = -1;
        }
        for (auto j : prime) {
            if (i * j > n) break;
            vis[i * j] = 1;
            if (i % j == 0) break;
            u[i * j] = -u[i];
        }
    }
    std::vector<int> pre(u.size());
    std::partial_sum(u.begin(), u.end(), pre.begin());
    return pre;
}
static auto U = Init(5e4 + 5);

int calc(int n, int m, int k) {
    n /= k, m /= k;
    int ans = 0;
    for (int i = 1; i <= std::min(n, m); ++i) {
        int r = std::min(n / (n / i), m / (m / i));
        ans += (U[r] - U[i - 1]) * (n / i) * (m / i);
        i = r;
    }
    return ans;
}

void solve() {
    int a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;
    std::cout << calc(b, d, k) - calc(a - 1, d, k) - calc(b, c - 1, k) +
                     calc(a - 1, c - 1, k)
              << '\n';
}