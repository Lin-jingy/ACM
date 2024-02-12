#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    if(a.find(b) != a.npos) {
        std::cout << 0 << '\n';
        return ;
    }
    for(int i = 1; i <= 7; ++i) {
        a += a;
        if(a.find(b) != a.npos) {
            std::cout << i << '\n';
            return ;
        }
    }
    std::cout << "-1\n";



}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
