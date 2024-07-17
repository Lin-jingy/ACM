#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    

    std::deque<int> dq;
    int sum = 0;
    for(int i = 1; i <= k; ++i) sum += a[i], dq.push_back(a[i]);
    int ans = (n - k) * sum;
    int rs = sum;
    for(int i = k; i >= 1; --i) {
        ans += rs;
        rs -= a[i];
    }

    int num = a.begin() + 1 + k - std::upper_bound(a.begin() + 1, a.end(), m);
    int pp = 0;
    for(int i = 1; i < k - num + 1; ++i) pp += a[i];

    int pre = 0;
    std::vector<int> mid(k + 1);
    for(int i = 1; i <= k; ++i) mid[i] = mid[i - 1] + a[i];
    for(int i = 1; i <= k; ++i) pre += mid[i];

    int lasts = 0;
    for(int i = 1; i <= k; ++i) {
        if(dq.back() < m) break;
        lasts += sum;
        int ls = sum - pp;
        sum -= dq.back();
        sum += m;
        pre = pre - ls + num * m;
        ++n;
        ans = std::min(ans, (n - k) * sum + pre + lasts);
        dq.pop_back();
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