#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;
    int q;
    std::cin >> q;
    std::array<char, 26> p;
    for(int i = 0; i < 26; ++i) p[i] = 'a' + i;
    while(q--) {
        char a, b;
        std::cin >> a >> b;
        for(int i = 0; i < 26; ++i) {
            if(p[i] == a) p[i] = b;
        }
    }
    for(auto i:s) {
        std::cout << p[i - 'a'];
    }

    return 0;
}