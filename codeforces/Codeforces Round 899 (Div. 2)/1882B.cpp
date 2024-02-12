#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::set<int>> a(n);
    std::set<int> s;

    for(int i = 0; i < n; ++i) {
        int m, x;
        std::cin >> m;
        while(m--) {
            std::cin >> x;
            a[i].insert(x);
            s.insert(x);
        }
    }

    int mx = 0;

    for(auto i:s) {
        std::set<int> ans;
        for(int j = 0; j < n; ++j) {
            if(!a[j].count(i)) for(auto k:a[j]) ans.insert(k);
        }
        mx = std::max(mx, (int)ans.size());
    }

    std::cout << mx << '\n';
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}