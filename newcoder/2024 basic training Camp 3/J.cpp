#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> v1(n + 1), v2(m + 1);
    while (k--) {
        int a, b;
        std::cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    double a = 0, b = 0;
    std::unordered_map<int, double> mp;
    for (int i = 1; i <= n; ++i) {
        for (auto j : v1[i]) {
            if (!mp.count(j))
                mp[j] = 1 - 1.0 / v1[i].size();
            else {
                mp[j] *= 1 - 1.0 / v1[i].size();
            }
        }
    }
    for (auto i : mp) {
        a += 1.0 - i.second;
    }
    mp.clear();
    for (int i = 1; i <= m; ++i) {
        for (auto j : v2[i]) {
            if (!mp.count(j))
                mp[j] = 1 - 1.0 / v2[i].size();
            else {
                mp[j] *= 1 - 1.0 / v2[i].size();
            }
        }
    }
    for (auto i : mp) {
        b += 1.0 - i.second;
    }
    printf("float\n%.8lf %.8lf\n", b, a);
    return 0;
}
