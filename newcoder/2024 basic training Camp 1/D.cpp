#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &i : a) std::cin >> i;
    std::sort(a.begin(), a.end());
    int d = a[a.size() / 2];
    for (int i = 0; i < n; ++i) a[i] -= d;
    std::unordered_set<int> s;
    s.insert(0);
    auto calc = [&](int x) {
        int res = 1;
        for (auto j : a) {
            res *= j + x;
            if (res >= 1e9 || res <= -1e9) return false;
        }
        s.insert(res);
        return true;
    };
    d = 0;
    if (!calc(0)) {
        for (int i = -200; i <= 200; ++i)
            if (calc(i)) break;
    }
    for (int i = 0;; ++i)
        if (!calc(i)) break;
    for (int i = -1;; --i)
        if (!calc(i)) break;
    while (q--) {
        int x;
        std::cin >> x;
        if (s.count(x))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    // std::cout << s.size();
    return 0;
}

// 44721
