#include <bits/stdc++.h>
namespace Tree{
    // 获取树的重心
static std::pair<int, int> get_centroid(std::vector<std::vector<int>> &v) {
    size_t size = v.size() - 1;
    std::pair<int, int> ans = {-1, -1};
    auto dfs = [&](auto dfs, int p, int fa) -> int {
        bool flag = true;
        int sum = 1;
        for (auto i : v[p]) {
            if (i == fa) continue;
            int s = dfs(dfs, i, p);
            if (s > size / 2) flag = false;
            sum += s;
        }
        if (size - sum > size / 2) flag = false;
        if (flag) {
            if (ans.first == -1)
                ans.first = p;
            else
                ans.second = p;
        }
        return sum;
    };
    dfs(dfs, 1, 0);
    return ans;
}
// 获取树的直径长
static int get_diameter_length(std::vector<std::vector<std::pair<int, int>>> &v) {
    size_t size = v.size() - 1;
    std::vector<int> dp1(size + 1), dp2(size + 1);
    int ans = 0;
    auto dfs = [&](auto dfs, int p, int fa) -> void {
        for (auto [i, j] : v[p]) {
            if (i == fa) continue;
            dfs(dfs, i, p);
            int t = dp1[i] + j;
            if (t > dp1[p])
                dp2[p] = dp1[p], dp1[p] = t;
            else if (t > dp2[p])
                dp2[p] = t;
        }
        ans = std::max(ans, dp1[p] + dp2[p]);
    };
    dfs(dfs, 1, 0);
    return ans;
}
// 获取树的直径的两端点
static std::pair<int, int> get_diameter_point(std::vector<std::vector<std::pair<int, int>>> &v) {
    size_t size = v.size() - 1;
    std::pair<int, int> ans;
    int c = 1;
    std::vector<int> d(size + 1);
    auto dfs = [&](auto dfs, int p, int fa) -> void {
        for (auto [i, j] : v[p]) {
            if (i == fa) continue;
            d[i] = d[p] + j;
            if (d[i] > d[c]) c = i;
            dfs(dfs, i, p);
        }
    };
    dfs(dfs, 1, 0);
    ans.first = c;
    d[c] = 0;
    dfs(dfs, c, 0);
    ans.second = c;
    return ans;
}
}