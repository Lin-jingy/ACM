#include <bits/stdc++.h>

#define int long long
constexpr int N = 1e5 + 5;
int a[N], b[N];
using std::abs;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= n; ++i) std::cin >> b[i];
    std::sort(a + 1, a + 1 + n);
    a[0] = -1e13, a[n + 1] = 1e13;
    int ans = abs(a[1] - b[1]), pa = 1, pb = 1;
    for(int i = 1; i <= n; ++i) {
        auto r = std::lower_bound(a + 1, a + 1 + n, b[i]) - a;
        auto l = r - 1;
        if(std::min(abs(a[r] - b[i]), abs(a[l] - b[i])) < ans) {
            ans = std::min(abs(a[r] - b[i]), abs(a[l] - b[i]));
            pb = i;
            if(abs(a[r] - b[i]) < abs(a[l] - b[i])) pa = r;
            else pa = l;
        }
    }
    std::swap(a[pa], a[pb]);
    for(int i = 1; i <= n; ++i) std::cout << a[i] << ' ';

    return 0;
}