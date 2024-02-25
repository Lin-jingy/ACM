#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for(auto i:s) mp[i]++; 
    for(auto i:mp) {
        if(i.second == 1) {
            for(int j = 0; j < s.size(); ++j) {
                if(s[j] == i.first) {
                    std::cout << j + 1;
                    return 0;
                }
            }
        }
    }

    return 0;
}