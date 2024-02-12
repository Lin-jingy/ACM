#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#define int long long
constexpr int mod = 998244353;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n + 1);
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i] >> s[i];
    }
    std::vector<bool> vis(n + 1);

    auto check = [&](int pos) -> int {
        std::vector<int> list;
        int j;
        for (j = pos; !vis[j]; j = v[j]) {
            list.push_back(j);
            vis[j] = true;
        }
        auto it = std::find(list.begin(), list.end(), j);
        if (it == list.end()) return 1;
        list = {it, list.end()};
        int res = 0;
        for (int i = 0; i < 5; i += 1) {
            j = i;
            for (int ci : list) j = s[ci][j] - 'A';
            if (j == i) res++;
        }
        return res;
    };
    int ans = 1, x;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        ans = ans * check(i) % mod;
    }
    std::cout << ans << '\n';

    return 0;
}
