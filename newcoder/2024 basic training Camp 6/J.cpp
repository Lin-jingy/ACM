#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector<std::vector<int>> v(n + 1);
    for(int i = 2; i <= n; ++i) {
        int x;
        std::cin >> x;
        v[x].push_back(i);
    }
    std::vector<int> ans(n + 1);
    auto dfs = [&](auto &&self, int p, int fa) -> std::vector<int> {
        std::vector<int> list;
        for(auto i:v[p]) {
            if(i == fa) continue;
            for(auto j:self(self, i, p)) list.push_back(j);
        }
        list.push_back(p);
        if(s[p] == 'R') {
            if(list.size() == 1) {
                std::cout << "-1\n";
                exit(0);
            }
            int k = (list.size() / 3 + 1) * 3 - list.size();
            for(int i = 1; i <= k; ++i) ans[list.back()] = 2, list.pop_back();
            while(!list.empty()) ans[list.back()] = 1, list.pop_back();
        }
        return list;
    };
    std::vector<int> list = dfs(dfs, 1, 0);
    while(!list.empty()) ans[list.back()] = 1, list.pop_back();
    for(int i = 1; i <= n; ++i) std::cout << ans[i];
    return 0;
}