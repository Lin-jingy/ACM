#include <algorithm>
#include <bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> p = {0, 1, 1};
    while(p.back() <= 1e9) {
        p.push_back(p[p.size() - 1] + p[p.size() - 2]);
    }
    std::unordered_map<int, std::array<int, 3>> mp;
    for(int i = 0; i < p.size(); ++i) {
        for(int j = 0; j < p.size(); ++j) {
            for(int k = 0; k < p.size(); ++k) {
                mp[p[i] + p[j] + p[k]] = {p[i], p[j], p[k]};
            }
        }
    }
    int q;
    std::cin >> q;
    while(q--) {
        int n;
        std::cin >> n;
        if(mp.count(n))  {
            auto &it = mp[n];
            std::cout << it[0] << ' ' << it[1] << ' ' << it[2] << '\n';
        }
        else std::cout << "-1\n";
    }

    return 0;
}