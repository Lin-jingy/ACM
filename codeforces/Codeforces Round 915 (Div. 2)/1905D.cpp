#include <bits/stdc++.h>

#define int long long
using PII = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::deque<PII> dq;
    std::unordered_set<int> s;
    int f = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        while (s.count(f)) ++f;
        dq.emplace_back(PII{f, 1});
        sum += f;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum -= dq.front().first;
        if (--dq.front().second == 0) dq.pop_front();
        int num = 0;
        while (!dq.empty() and dq.back().first > a[i]) {
            num += dq.back().second;
            sum -= dq.back().second * dq.back().first;
            dq.pop_back();
        }
        sum += num * a[i] + n;
        dq.emplace_back(PII{a[i], num});
        dq.emplace_back(PII{n, 1});
        ans = std::max(ans, sum);
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
