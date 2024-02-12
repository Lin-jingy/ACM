#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> t(n), x(n);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i] >> x[i];

    int ans = 0;
    std::multiset<int> mp;
    std::vector<int> a;
    for (int i = n - 1; i >= 0; --i) {
        if (t[i] == 1) {
            if (mp.count(x[i])) {
                a.push_back(1);
                mp.erase(mp.find(x[i]));
            }else {
                a.push_back(0);
            }
        } else {
            mp.insert(x[i]);
        }
        ans = std::max(ans, (int)mp.size());
    }
    if (!mp.empty()) {
        std::cout << -1 << '\n';
    } else {
        std::reverse(a.begin(), a.end());
        std::cout << ans << '\n';
        for(auto i:a)
            std::cout << i << ' ';
    }
    return 0;
}
