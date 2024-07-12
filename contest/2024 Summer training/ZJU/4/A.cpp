#include <bits/stdc++.h>

constexpr int N = 1005;
int v[N][N];
std::pair<int, int> graph[N][N];
bool vis[N][N];
int n, m;
int x1, y1, x2, y2;
int px[] = {0, 0, 1, -1};
int py[] = {1, -1, 0, 0};

void dij() {
    std::priority_queue<std::array<int, 3>> q;
    q.push({INT_MAX, x1, y1});
    vis[x1][y1] = 1;
    while(!q.empty()) {
        auto [val, x, y] = q.top();
        q.pop();
        if(x == x2 and y == y2) return ;
        for(int i = 0; i < 4; ++i) {
            int rx = x + px[i];
            int ry = y + py[i];
            if(rx >= 1 and rx <= n and ry >= 1 and ry <= m and !vis[rx][ry]) {
                vis[rx][ry] = 1;
                graph[rx][ry] = {x, y};
                q.push({v[rx][ry], rx, ry});
            }
        }
    }
}

void dfs(int x, int y) {
    if(x == 0 and y == 0) return ;
    vis[x][y] = 1;
    dfs(graph[x][y].first, graph[x][y].second);
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m;
    std::cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n * m; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[x][y] = i;
    }
    dij();
    memset(vis, 0, sizeof(vis));
    dfs(x2, y2);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(vis[i][j]) std::cout << '.';
            else std::cout << '#';
        }
        std::cout << '\n';
    }
    
    return 0;
}