#include<bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &i:a) std::cin >> i;
    std::sort(a.begin(), a.end());

    int mx = a.back(), mn = a.front();
    int sum = 0;
    std::vector<int> ans;
    while(mx != mn) {
        ans.emplace_back(mn);
        mx = mx + mn >> 1, mn = mn + mn >> 1;
        ++sum;
    }
    std::cout << sum << '\n';
    if(ans.size() <= n) for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}