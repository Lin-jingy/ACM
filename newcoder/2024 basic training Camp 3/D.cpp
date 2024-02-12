#include <bits/stdc++.h>

#define int long long

int max_sub_sum(std::vector<int> &a) {
    int mx = -1e18;
    for (auto i : a) mx = std::max(mx, i);
    if (mx <= 0) return mx;
    int thisSum = 0, maxSum = 0;
    int i;
    for (i = 0; i < a.size(); i++) {
        thisSum += a[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;
    if (k == 0) {
        std::cout << max_sub_sum(a) << '\n';
    } else {
        int ans = -1e18;
        for (int i = 1; i < n; ++i) {
            std::swap(a[i], a[i - 1]);
            ans = std::max(ans, max_sub_sum(a));
            std::swap(a[i], a[i - 1]);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
