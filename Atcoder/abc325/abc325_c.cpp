#include <bits/stdc++.h>

int xp[] = {0, 0, 1, 1, 1, -1, -1, -1};
int yp[] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
    std::vector<std::pair<int, int>> p;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#')
                p.emplace_back(std::pair<int, int>{i, j});
        }
    }

    while (!p.empty()) {
        std::queue<std::pair<int, int>> q;
        while (!p.empty()) {
            if (!vis[p.back().first][p.back().second]) {
                q.push(p.back());
                ++ans;
                p.pop_back();
                break;
            }
            p.pop_back();
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            for (int i = 0; i < 8; ++i) {
                int rx = x + xp[i];
                int ry = y + yp[i];
                if (rx >= 0 and rx < n and ry >= 0 and ry < m and s[rx][ry] == '#')
                    q.push({rx, ry});
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}
