#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::deque<char> q;
    for (auto i : s) q.push_back(i);
    while (!q.empty() and q.back() == 'W') q.pop_back();
    while (!q.empty() and q.front() == 'W') q.pop_front();
    std::cout << q.size() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
