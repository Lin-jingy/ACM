#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> v(n + 1);
    for(int i = 2; i <= n; ++i) {
        int x;
        std::cin >> x;
        v[x].push_back(i);
    }
    int l = 1, r = n, ans = 0;
    auto check = [&](int mid)->bool {
        int ans = 0;
        std::vector<int> size(n + 1);
        auto dfs = [&](auto self, int p) ->void {
            for(auto i:v[p]) {
                self(self, i);
                size[p] += size[i];
            }
            if(size[p] >= mid) {
                ++ans;
                size[p] = 0;
            } else size[p]++;
        };
        dfs(dfs, 1);
        return ans <= k;
    };
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';


    return 0;
}
