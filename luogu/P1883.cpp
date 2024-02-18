#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

constexpr double eps = 1e-8;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> v(n);
    for(auto &i:v) std::cin >> i[0] >> i[1] >> i[2];
    auto fun = [&](double x) ->double {
        double k = -1e10;
        for(auto i:v) {
            k = std::max(k, x * x * i[0] + x * i[1] + i[2]);
        }
        return k;
    };
    double r = 1000, l = 0;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(fun(mid - eps) > fun(mid + eps)) l = mid;
        else r = mid;
    }
    printf("%.4lf\n", fun(l));

}


int main() {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    
    int T = 1;
    std::cin >> T;
    while(T--) solve();

    return 0;
}