#include <bits/stdc++.h>

constexpr int N = 31;

std::array<int, N> operator-(const std::array<int, N> &a,
                             const std::array<int, N> &b) {
    std::array<int, N> tmp;
    for (int i = 0; i < N; ++i) tmp[i] = a[i] - b[i];
    return tmp;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    std::vector<std::array<int, N>> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        std::bitset<N> bit(a[i]);
        for (int j = 0; j < N; ++j) pre[i][j] += bit[j];
    }

    auto getAns = [&](int l, int r) -> int {
        int len = r - l + 1;
        int ans = 0;
        std::array<int, N> ch = pre[r] - pre[l - 1];
        for (int i = 0; i < N; ++i) {
            if (ch[i] * 2 < len) ans += 1 << i;
        }
        return ans;
    };

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << getAns(l, r) << '\n';
    }

    return 0;
}