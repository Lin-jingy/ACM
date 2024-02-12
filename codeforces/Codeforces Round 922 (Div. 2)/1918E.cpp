#include <algorithm>
#include <cassert>
#include <chrono>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

std::mt19937 rng(time(0));

void solve() {
    int n;
    int sum = 0;
    auto ask = [&](int k) {
        ++sum;
        std::cout << "? " << k + 1 << std::endl;
        char x;
        std::cin >> x;
        return x;
        if (x != '<' && x != '>' && x != '=') exit(0);
    };
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i;
    std::shuffle(a.begin(), a.end(), rng);
    auto dfs = [&](auto &&dfs, int l, int r) -> void {
        if (l >= r) return;
        int x = a[l];
        while (ask(x) != '=')
            ;
        std::deque<int> dq;
        dq.push_back(x);
        int sz = 0;
        for (int i = l + 1; i <= r; i++) {
            if (ask(a[i]) == '<') dq.push_front(a[i]), ++sz;
            else dq.push_back(a[i]);
            ask(x);
        }
        for (int i = l; i <= r; ++i) a[i] = dq.front(), dq.pop_front();
        dfs(dfs, l, l + sz - 1);
        dfs(dfs, l + sz + 1, r);
    };
    dfs(dfs, 0, n - 1);
    assert(sum <= 40 * n);
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[a[i]] = i + 1;
    std::cout << "! ";
    for (int i = 0; i < n; ++i) std::cout << ans[i] << ' ';
    std::cout << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}