#include <bits/stdc++.h>

std::vector<int> list;
void dfs(int last, int n) {
    if (n == 0) {
        if (list.size() == 1) return;
        std::cout << list.front();
        for (int i = 1; i < (int)list.size(); ++i) std::cout << "+" << list[i];
        std::cout << '\n';
        return;
    }
    for (int i = last; i <= n; ++i) {
        list.push_back(i);
        dfs(i, n - i);
        list.pop_back();
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    dfs(1, n);

    return 0;
}