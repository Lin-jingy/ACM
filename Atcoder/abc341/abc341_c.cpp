#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n, m, len;
    std::cin >> n >> m >> len;
    std::string T;
    std::cin >> T;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i) std::cin >> v[i];
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int x = i, y = j;
            if(v[i][j] == '#') continue;
            for(auto k:T) {
                if(k == 'L') y--;
                else if(k == 'R') y++;
                else if(k == 'U') x--;
                else if(k == 'D') x++;
                if(!(x >= 0 and x < n and y >= 0 and y < m and v[x][y] == '.')) goto NEXT;
            }
            ans++;
            NEXT:;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}