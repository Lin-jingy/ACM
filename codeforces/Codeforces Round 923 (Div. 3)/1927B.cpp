#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<char> ans;
    std::vector<std::vector<int> > v(n + 1);
    for (char i = 'a'; i <= 'z'; ++i) v[0].push_back(i);
    for (int i = 0; i < n; ++i) {
        ans.push_back(v[a[i]].back());
        v[a[i] + 1].push_back(v[a[i]].back());
        v[a[i]].pop_back();
    }
    for (auto i : ans) std::cout << i;
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
