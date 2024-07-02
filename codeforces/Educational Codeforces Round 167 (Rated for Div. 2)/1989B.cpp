#include <bits/stdc++.h>

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < b.size(); ++i) {
        int k = 0;
        int index = i;
        for(int j = 0; j < a.size(); ++j) {
            if(a[j] == b[index]) ++index, ++k;
        }
        ans = std::max(ans, k);
    }
    std::cout << a.size() + b.size() - ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}