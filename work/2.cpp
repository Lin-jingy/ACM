#include <bits/stdc++.h>

char v[305][305];
bool vis[305][305];
int n, m;
std::pair<int, int> begin;
std::vector<std::pair<int, int>> p[26];

int px[] = {1, -1, 0, 0};
int py[] = {0, 0, 1, -1};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> v[i][j];
            if (v[i][j] == '@') begin = {i, j};
            else if (v[i][j] >= 'A' && v[i][j] <= 'Z') {
                p[v[i][j] - 'A'].emplace_back(i, j);
            }
        }
    }

    std::queue<std::tuple<int, int, int>> q;
    q.emplace(begin.first, begin.second, 0);

    while (!q.empty()) {
        auto [x, y, dis] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (v[x][y] == '=') {
            std::cout << dis << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int xx = x + px[i];
            int yy = y + py[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                if (v[xx][yy] == '.' || v[xx][yy] == '=')
                    q.emplace(xx, yy, dis + 1);
                if (v[xx][yy] >= 'A' && v[xx][yy] <= 'Z') {
                    auto &pos = p[v[xx][yy] - 'A'];
                    if (pos[0].first == xx && pos[0].second == yy)
                        q.emplace(pos[1].first, pos[1].second, dis + 1);
                    else q.emplace(pos[0].first, pos[0].second, dis + 1);
                }
            }
        }
    }

    return 0;
}