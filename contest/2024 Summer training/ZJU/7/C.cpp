#include <bits/stdc++.h>

using Pii = std::pair<int, std::bitset<18>>;

struct node {
    int val;
    std::bitset<18> bit;
    friend bool operator< (const node &a, const node &b) {
        return a.val > b.val;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::unordered_set<int> s;
    for(int i = 1; i <= n; ++i) std::cin >> a[i], s.insert(a[i]);
    std::priority_queue<node> q;
    q.push({0, std::bitset<18>(a[1])});
    s.erase(a[1]);
    std::vector<int> dis(1 << 18, 20);
    dis[a[1]] = 0;
    int ans = 0;
    while(!q.empty()) {
        auto [val, point] = q.top();
        int p = point.to_ulong();
        q.pop();
        if(dis[p] > val) dis[p] = val;
        if(s.count(p)) {
            ans += dis[p];
            dis[p] = 0;
            s.erase(p);
        }
        for(int i = 0; i < 18; ++i) {
            point.flip(i);
            int to = point.to_ulong();
            point.flip(i);
            if(dis[to] > dis[p] + 1) {
                dis[to] = dis[p] + 1;
                q.push({dis[to], std::bitset<18>(to)});
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}