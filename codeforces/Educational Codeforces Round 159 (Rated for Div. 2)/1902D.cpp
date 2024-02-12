#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector<std::pair<int, int>> p(n + 1);
    std::map<std::pair<int, int>, std::set<int>> mp;
    mp[{0, 0}].insert(0);
    for(int i = 1, x = 0, y = 0; i <= n; ++i) {
        if(s[i] == 'U') ++y;
        else if(s[i] == 'D') --y;
        else if(s[i] == 'L') --x;
        else ++x;
        p[i] = {x, y};
        mp[{x, y}].insert(i);
    }
    auto check = [&](int x, int y, int l, int r) -> bool {
        auto &ss = mp[{x, y}];
        auto it = ss.lower_bound(l);
        if(it != ss.end() and *it <= r) return true;
        else return false;
    };
    while(q--) {
        int x, y, l, r;
        std::cin >> x >> y >> l >> r;
        --l;
        if(check(x, y, 0, l) or check(x, y, r, n) or check(p[l].first + p[r].first - x, p[l].second + p[r].second - y, l, r)) {
            std::cout << "YES\n";
        }else {
            std::cout << "NO\n";
        }
        

    }

    return 0;
}
