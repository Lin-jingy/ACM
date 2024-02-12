#include<bits/stdc++.h>
#define int long long
int a[300010];

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        if (n % 2 == 0) {
            for (int i = 2; i < n; ++i) a[i + 1] += a[i - 1] - a[i], a[i] = a[i - 1];
            if (a[n - 1] > a[n]) {
                std::cout << "NO\n";
                goto A;
            }
            else {
                std::cout << "YES\n";
                goto A;
            }
        }else std::cout << "YES\n";
    A:;
    }
    return 0;
}