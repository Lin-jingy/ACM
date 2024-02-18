#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#define int long long

inline int C(int x) { return x * (x - 1) / 2; }

void solve() {
    int n, b, x;
    std::cin >> n >> b >> x;
    int ans = 0, mx = 0;
    std::vector<int> a(n);
    for(int &i:a) std::cin >> i, mx = std::max(mx, i);
    int L = 1,  R = mx;
    auto fun = [&](int k)->int {
        int mx = 0;
        for(auto i:a) mx += C(i) - (k - i % k) * C(i / k) - (i % k) * C(i / k + 1);
        return mx * b - (k - 1) * x;
    };
    while(L < R) {
        int l = L + (R - L) / 3, r = R - (R - L) / 3;
        if(fun(l) > fun(r)) R = r - 1;
        else L = l + 1;
    }
    std::cout << fun(L) << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}