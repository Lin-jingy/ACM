#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    for (int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    auto dfs = [&](auto dfs, int p, int fa) -> int {
        int num = 1;
        int mx = 0;
        for (auto i : v[p]) {
            if (i == fa)
                continue;
            int k = dfs(dfs, i, p);
            mx = std::max(mx, k);
            num += k;
        }
        if(p == 1)
            return num - mx;
        return num;
    };

    std::cout << dfs(dfs, 1, 0) << '\n';

    return 0;
}
