#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string a[n];
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::string s = "akiv";
    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < n; ++i) {
            if(s.empty()) goto A;
            if(a[i][j] == s.back()) {
                s.pop_back();
                break;
            }
        }
    }
    A:;
    if(s.empty()) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
