#include <bits/stdc++.h>

using Pii = std::pair<int, int>;
int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::vector<std::vector<bool>> v(n + 1, std::vector<bool>(m + 1));
    std::vector<Pii> list;
    std::vector<std::vector<int>> V(n + 1, std::vector<int>(m + 1, INT_MAX));
    bool ok = 0;
    std::set<Pii> s;
    auto dfs = [&](auto self, int x, int y, int val)->void {
        if(x == x2 and y == y2) {
            s.clear();
            for(auto i:list) s.insert(i);
            ok = 1;
            return ;
        }
        if(V[x][y] <= val) return ;
        V[x][y] = val;
        for(int i = 0; i < 4; ++i) {
            int rx = x + px[i];
            int ry = y + py[i];
            if(rx >= 1 and rx <= n and ry >= 1 and ry <= m and v[rx][ry] == 0) {
                list.emplace_back(rx, ry);
                self(self, rx, ry, val + 1);
                list.pop_back();         
            } 
        }
    };
    for(int i = 1; i < std::min(n, m); ++i) {
        int x, y;
        std::cin >> x >> y;
        if(x == x1 and y == y1) continue;
        if(x == x2 and y == y2) continue;
        v[x][y] = 1;
    }
    dfs(dfs, x1, y1, 0);
    bool FF = 1;
    for(int i = std::min(n, m); i <= n * m; ++i) {
        int x, y;
        std::cin >> x >> y;
        if(x == x1 and y == y1) continue;
        if(x == x2 and y == y2) continue;
        if(!s.count({x, y})) v[x][y] = 1;
        else {
            if(!FF) continue;
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) V[i][j] = INT_MAX;
            }
            ok = 0;
            v[x][y] = 1;
            dfs(dfs, x1, y1, 0);
            if(ok == 0) {
                FF = 0;
                v[x][y] = 0;
                continue;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(v[i][j]) std::cout << '#';
            else std::cout << '.';
        }
        std::cout << '\n';
    }
    return 0;
}