#include<bits/stdc++.h>

bool check(int month, int day) {
    std::vector<int> m;
    std::vector<int> d;
    while(month) {
        m.emplace_back(month % 10);
        month /= 10;
    }
    while(day) {
        d.emplace_back(day % 10);
        day /= 10;
    }
    for(int i = 1; i < m.size(); ++i) if(m[i] != m[0]) return false;
    for(auto i:d) if(i != m.back()) return false;
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    int ans = 0; 
    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        for(int j = 1; j <= x; ++j) if(check(i, j)) ++ans;
    }
    std::cout << ans << '\n';

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}