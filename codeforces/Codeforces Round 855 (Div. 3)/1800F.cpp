#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;
std::string s[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> s[i];
    std::unordered_map<std::bitset<26>, int> mp;
    for(int i = 1; i <= n; ++i) {
        std::bitset<26> bit;
        for(auto j:s[i]) bit[j - 'a'] = !bit[j - 'a'];
        mp[bit]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        std::bitset<26> bit, g;
        for(auto j:s[i]) bit[j - 'a'] = !bit[j - 'a'];
        std::vector<bool> p(26);
        for(auto j:s[i]) p[j - 'a'] = 1;
        for(int j = 0; j < 26; ++j) {
            if(p[j]) continue;
            g.reset();
            g[j] = 1;
            g ^= bit;
            if(mp.count(g)) ans += mp[g];
        }
    }
    std::cout << ans << '\n';
    

    return 0;
}