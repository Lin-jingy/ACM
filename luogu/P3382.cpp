#include <algorithm>
#include <iostream>
#include <vector>

constexpr double eps = 1e-8;


int main() {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    
    int n;
    double l, r;
    std::cin >> n >> l >> r;
    std::vector<double> a(n + 1);
    for(double &i:a) std::cin >> i;
    std::reverse(a.begin(), a.end());
    auto f = [&](double x) -> double {
        double k = 1;
        double ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans += a[i] * k;
            k *= x;
        }
        return ans;
    };
    int T = 1e3;
    while(T--) {
        double mid = (l + r) / 2;
        if(f(mid - eps) < f(mid + eps)) l = mid;
        else r = mid; 
    }
    std::cout << l << '\n';

    return 0;
}