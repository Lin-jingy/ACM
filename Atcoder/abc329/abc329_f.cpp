#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::set<int>> v(n + 1);
    for(int i = 1, x; i <= n; ++i) std::cin >> x, v[i].insert(x);
    while(q--) {
        int a, b;
        std::cin >> a >> b;
        if(v[b].empty()) v[a].swap(v[b]);
        else {
            if(v[a].size() > v[b].size()) {
                for(auto i:v[b]) v[a].insert(i);
                v[b].clear();
                v[a].swap(v[b]);
            }else {
                for(auto i:v[a]) v[b].insert(i);
                v[a].clear();
            }
        }
        std::cout << v[b].size() << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}
