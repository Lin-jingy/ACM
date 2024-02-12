#include <deque>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n + 2);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        long long l = 1, r = 1e15, ans = 0;
        auto check = [&](long long x) -> bool {
            std::vector<long long> dp(n + 2);
            std::deque<int> q;
            long long sum = 0;
            q.push_back(0);
            for (int i = 1, j = 0; i <= n + 1; ++i) {
                while (sum > x) sum -= a[++j];
                while (!q.empty() && q.front() < j) q.pop_front();
                if (q.empty()) return false;
                dp[i] = dp[q.front()] + a[i];
                while (!q.empty() && dp[i] < dp[q.back()]) q.pop_back();
                q.push_back(i);
                sum += a[i];
            }
            if (dp.back() > x) return false;
            return true;
        };
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        std::cout << ans << '\n';
    }
}