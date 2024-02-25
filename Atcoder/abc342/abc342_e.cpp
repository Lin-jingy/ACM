#include <bits/stdc++.h>

using std::vector;
using std::array;
#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    vector<vector<array<int, 5>>> v(N + 1);
    for(int i = 1; i <= M; ++i) {
        int L, D, K, C, A, B;
        std::cin >> L >> D >> K >> C >> A >> B;
        v[B].push_back({L, D, K, C, A});
    }

    vector<bool> vis(N + 1);
    vector<int> dis(N + 1);
    std::priority_queue<std::pair<int, int>> q;
    q.push({4e18, N});
    while(not q.empty()) {
        auto [time, pos] = q.top();
        q.pop();
        if(vis[pos]) continue;
        vis[pos] = 1;
        dis[pos] = time;
        for(auto [l, d, k, c, a]:v[pos]) {
            if(time - c >= l) {
                int T = l + std::min((time - c - l) / d, k - 1) * d;
                q.push({T, a});
            }
        }
    }

    for(int i = 1; i < N; ++i) {
        if(dis[i] == 0) std::cout << "Unreachable\n";
        else std::cout << dis[i] << '\n';
    }


    return 0;
}