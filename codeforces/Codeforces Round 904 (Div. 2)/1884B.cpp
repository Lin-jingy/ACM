#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> r;
    for(int i = 0; i < n; ++i) if(s[i] == '0') r.emplace_back(i);
    int add = 0;
    for(int i = 1; i <= n; ++i) {
        if(r.empty()) {
            std::cout << "-1 ";
            continue;
        }
        int pos = n - i;
        add += pos - r.back();
        r.pop_back();
        std::cout << add << ' ' ;
    }
    std::cout << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}