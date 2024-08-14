#include <bits/stdc++.h>

void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

class BIT {
   private:
    constexpr int lowbit(int x) { return x & (-x); }
    std::vector<int> c;
    int n;

   public:
    BIT(int N) : c(N + 1), n(N) {}
    void insert(int i, int val) {
        for (; i <= n; i += lowbit(i)) c[i] = std::max(c[i], val);
    }
    int pre(int i) {
        int max = 0;
        for (; i > 0; i -= lowbit(i)) max = std::max(max, c[i]);
        return max;
    }
};

void solve() {
    int n;
    while (std::cin >> n) {
        std::vector<int> a(n + 1);
        std::map<int, int> mp;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], mp.emplace(a[i], 1);
        int f = 0;
        for (auto &[i, j] : mp) j = ++f;
        std::vector<int> dp1(n + 1), dp2(n + 1);
        BIT T1(n + 1), T2(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp1[i] = T1.pre(mp[a[i]] - 1) + 1;
            T1.insert(mp[a[i]], dp1[i]);
        }
        for (int i = n; i >= 1; --i) {
            dp2[i] = T2.pre(mp[a[i]] - 1) + 1;
            T2.insert(mp[a[i]], dp2[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = std::max(ans, std::min(dp1[i], dp2[i]));
        std::cout << ans * 2 - 1 << '\n';
    }
}