#include <iostream>
#include <queue>
#include <unordered_map>

void solve() {
    int n, x;
    std::cin >> n;
    std::unordered_map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        mp[x].push_back(i);
    }
    int ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int pos = n;
    while (pos > 0) {
        for (auto &i : mp) {
            while (!i.second.empty() && i.second.back() > pos) i.second.pop_back();
            if (!i.second.empty()) {
                q.push(i.second.back());
                i.second.pop_back();
            }
        }
        for (auto it = mp.begin(); it != mp.end();) {
            if (it->second.empty())
                it = mp.erase(it);
            else
                ++it;
        }
        pos = q.top();
        ans++;
        while (!q.empty()) q.pop();
        for (auto &i : mp) {
            while (!i.second.empty() && i.second.back() > pos) i.second.pop_back();
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
