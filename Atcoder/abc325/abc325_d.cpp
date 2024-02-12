#include <bits/stdc++.h>

#define int long long
using PII = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<PII> a(n);
    for (auto& [x, y] : a) {
        std::cin >> x >> y, y += x;
    }

    std::sort(a.begin(), a.end());

    int last = 0;
    int i = 0;
    int ans = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    while (true) {
        if (q.empty()) {
            if (i == n) {
                break;
            }
            last = std::max(last, a[i].first);
        }
        while (i < n && a[i].first <= last) {
            q.push(a[i].second);
            i++;
        }

        while (!q.empty() && q.top() < last) {
            q.pop();
        }
        if (!q.empty()) {
            ans += 1;
            q.pop();
        }
        last++;
    }

    std::cout << ans << "\n";

    return 0;
}
