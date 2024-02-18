#include <iostream>
#include <set>
#include <vector>

static std::vector<int> get_factor(int x) {  // O(sqrt(x))
    std::vector<int> factor;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            factor.push_back(i);
            if (i != x / i) factor.push_back(x / i);
        }
    }
    return std::move(factor);
}

void solve() {
    int n, x;
    std::cin >> n >> x;
    // int ans = 0;
    // for (int i = std::max(x, 2); i <= n; ++i) {
    //     int cn = n - i;
    //     int k = cn / (i - 1);
    //     cn %= i - 1;
    //     if((cn + 1 == x and k % 2 == 1) or (i - cn == x and k % 2 == 0)) {
    //         ++ans;
    //         std::cout << i << ' ';
    //         if(k == 0) break;
    //     }
    // }
    std::set<int> s;
    for(auto i:get_factor(n - x)) if(i / 2 >= x - 1 and i % 2 == 0) s.insert(i);
    for(auto i:get_factor(n + x - 2)) if(i / 2 >= x - 1 and i % 2 == 0) s.insert(i);
    std::cout << s.size() << '\n';
}

signed main() {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}