#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
    int n, k;
    std::cin >> n >> k;
    // std::vector<int> a(n + 1);
    // std::vector<int> pre(n + 1);
    // for (int i = 1; i <= n; ++i) a[i] = i;
    // do {
    //     std::vector<int> p;
    //     for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    //     for (int i = k; i <= n; ++i) p.push_back(pre[i] - pre[i - k]);
    //     std::sort(p.begin(), p.end());
    //     if (p.back() - p.front() <= 1) {
    //         for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    //         std::cout << '\n';
    //     }
    // } while (std::next_permutation(a.begin() + 1, a.end()));
    std::vector<int> ans(n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= k; ++i) {
        int num = n / k + ((n % k) >= i);
        if (i % 2 == 1) {
            int kl = l + num - 1;
            for (int j = i; j <= n; j += k) {
                ans[j] = kl--;
            }
            l = l + num;
        } else {
            int kr = r - num + 1;
            for (int j = i; j <= n; j += k) {
                ans[j] = kr++;
            }
            r = r - num;
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

// 10 4 24
// 11 4 25
// 5 2 6
/*
7 2   8
7 3   0
7 4   17



*/
