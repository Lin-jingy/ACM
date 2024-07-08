#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    if(s == "xy") {
        std::cout << 1 << '\n';
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < (int)s.size() - 2; ++i) {
        if(i == 0 and s[i] == 'x' and s[i + 1] == 'y') ++ans, s[i + 1] = 'x';
        else if(s[i] == 'y' and s[i + 1] == 'x' and s[i + 2] == 'y') s[i + 2] = 'x', ++ans;
    }
    std::cout << ans << '\n';
    return 0;
}