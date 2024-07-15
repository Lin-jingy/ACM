#include <bits/stdc++.h>

#define int long long
using Pii = std::pair<int, int>;
int n, m;

static int Dijkstra(const std::vector<std::vector<Pii>> &v, const std::vector<Pii> &time) {
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> q;
    std::vector<int> dis(n + 1, -1);
    q.push({0, time[1].first, 1});
    dis[1] = time[1].first;
    while (!q.empty()) {
        auto [l, r, pos] = q.top();
        q.pop();
        if(r < dis[pos]) continue;
        dis[pos] = r;
        if(pos == n) {
            return l;
        }
        for(auto [p, k] : v[pos]) {
            int nl = l + k, nr = r + k;
            if(nr <= time[p].first) {
                nr = time[p].first;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
            }
            else if(nl >= time[p].second) {
                nr = 1e16;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
            }
            else if(nl <= time[p].first and nr > time[p].first and nr < time[p].second) {
                nr = time[p].first;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
            }
            else if(nr >= time[p].second and nl > time[p].first and nl < time[p].second) {
                nl = time[p].second;
                nr = 1e16;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
            }
            else if(nl <= time[p].first and nr >= time[p].second) {
                nr = time[p].first;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
                nl = time[p].second, nr = 1e16;
                if(nr > dis[p]) q.push({std::max(nl, dis[p]), nr, p});
            }
        }
    }
    return -1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m;
    std::vector<Pii> time(n + 1);
    std::vector<std::vector<Pii>> v(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> time[i].first >> time[i].second;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }
    std::cout << Dijkstra(v, time) << '\n';
    return 0;
}