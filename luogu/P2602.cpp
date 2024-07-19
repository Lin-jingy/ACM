#include <bits/stdc++.h>

auto ch(int x) {
    std::vector<int> a;
    while(x) {
        a.push_back(x / 10);
        x /= 10;
    }
    return a;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<int, 15> dp;
    for(int i = 1; i <= 13; ++i) dp[i] = 10 * dp[i - 1] + pow(10, i - 1);

    int a, b;
    std::cin >> a >> b;

    auto ca = ch(a);
    auto cb = ch(b);

    std::array<int, 10> p;
    auto calc = [&](auto x, int add, int xa){
        for(int i = x.size() - 1; i >= 0; --i) {
            for(int j = 0; j < 10; ++j) p[j] += add * dp[i] * x[i];
            for(int j = 0; j < x[i]; ++j) p[j] += add * (int)std::pow(10, i);
            p[x[i]] += add * (xa % (int)std::pow(10, i));
        }
    };
    calc(cb, 1, b);
    calc(ca, -1, a);
    for(int i = 0; i < 10; ++i) std::cout << p[i] << ' ';
    return 0;
}