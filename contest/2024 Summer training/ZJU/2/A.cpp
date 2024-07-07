#include <bits/stdc++.h>

using Pii = std::pair<int, int>;

int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;
    int count1 = 0, count0 = 0;
    std::vector<std::vector<char>> v(n + 1, std::vector<char>(m +  1));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            std::cin >> v[i][j];
            if(v[i][j] == '0') ++count0;
            else if(v[i][j] == '1') ++count1; 
        }
    }
    std::queue<Pii> q;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(v[i][j] != 'X') {
                q.emplace(i, j);
                goto A;
            }
        }
    }
    A:;
    int c0 = 0, c1 = 0;
    std::vector<std::vector<bool>> vis(n + 1, std::vector<bool>(m + 1));
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if(vis[i][j]) continue;
        if(v[i][j] == '1') ++c1;
        else if(v[i][j] == '0') ++c0;
        vis[i][j] = 1;
        for(int k = 0; k < 4; ++k) {
            int x = i + px[k];
            int y = j + py[k];
            if(x >= 1 and x <= n and y >= 1 and y <= m and v[x][y] != 'X') q.emplace(x, y);
        }
    }
    if(c0 == count0 and c1 == count1 and c0 % 2 == 1) std::cout << "Yes\n";
    else std::cout << "No\n";
    
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}