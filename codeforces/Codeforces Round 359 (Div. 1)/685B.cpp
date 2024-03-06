#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> v(n + 1);
    std::vector<int> fa(n + 1);
    for(int i = 2; i <= n; ++i) {
        int f;
        std::cin >> f;
        v[f].push_back(i);
        fa[i] = f;
    }

    std::vector<int> size(n + 1), mx(n + 1), ans(n + 1);
    auto dfs = [&](auto &&self, int p) ->void {
        size[p] = 1;
        for(auto i:v[p]) {
            self(self, i);
            size[p] += size[i];
            mx[p] = std::max(mx[p], size[i]);
        }
        int MX = mx[p];
        ans[p] = p;
        for(auto i:v[p]) {
            int pos = ans[i];
            while(pos != p) {
                if(std::max(mx[pos], size[p] - size[pos]) <= size[p] / 2) {
                    ans[p] = pos;
                    break;
                } 
                pos = fa[pos];
            }
        }
    };
    dfs(dfs, 1);
    while(q--) {
        int x;
        std::cin >> x;
        std::cout << ans[x] << '\n';
    }

    return 0;
}