#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> s;
    for(auto &i:a) std::cin >> i, s.insert(i);
    if(n == 1) {
        std::cout << 1 << '\n';
        return ;
    }
    std::sort(a.begin(), a.end());
    int k = a.back() - a.front();
    long long ans = 0;
    for(auto i:a) k = std::__gcd(a.back() - i, k);
    for(int i = a.back(); ; i -= k) if(!s.count(i)) {
        ans += (a.back() - i) * 1LL / k;
        break;
    }
    for(auto i:a) ans += (a.back() - i) * 1LL / k;
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
