#include <bits/stdc++.h>

std::vector<bool> vis(1e6 + 10);
std::vector<int> p;

void init() {
    for(int i = 2; i * i <= 1e6; ++i) {
        if(!vis[i]) {
            p.push_back(i);
            for(int j = i + i; j <= 1e6; j += i) vis[j] = true;
        }
        
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int x;
    for(int i = 1; i <= n; ++i) {
        std::cin >> x;
        for(auto j:p) {
            if(j > x) break;
            while(x % j == 0) mp[j]++, x /= j;
            if(x == 1) break;
        }
        if(x != 1) mp[x]++;
    }
    for(auto [i, j]:mp) {
        if(j % n != 0) {
            std::cout << "NO\n";
            return ;
        }
    }
    std::cout << "YES\n";

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    init();
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
