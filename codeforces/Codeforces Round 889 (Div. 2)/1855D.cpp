// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

const int N = 2e5 + 5;
std::bitset<N> f;

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i(0); i < n; i++) std::cin >> a[i];
    std::vector<int> s(n + 1);
    for (int i(0); i < n; i++) s[i + 1] = s[i] + a[i];
    int ans(0);
    f[1] = 1;
    for (int i(0); i < n; i++) {
        f |= f << a[i];
        if (f[i + 1]) {   
            f[i + 1] = 0;
            ans = std::max(ans, s[i + 1] - i);
        }
    }
    for (int i = n; i <= 2 * n; i++) if (f[i]) ans = std::max(ans, s[n] - (i - 1));
    std::cout << ans << "\n";
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
