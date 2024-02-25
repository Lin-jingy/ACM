#include <bits/stdc++.h>

#define int long long
constexpr int N = 2e5 + 5;
int dp[N];
std::array<int, 2> p[N];


void init() {
    for(int i = 1; i < N; ++i) dp[i] = N;
    dp[0] = 0;
    for(int i = 1; ; ++i) {
        int sum = i * (i - 1) / 2;
        if(sum > N) break;
        for(int j = sum; j < N; ++j) {
            if(dp[j - sum] + i < dp[j]) {
                dp[j] = dp[j - sum] + i;
                p[j] = {i, j - sum};
            }
        }
    }
}

void solve() {
    int n, x, y, s;
    std::cin >> n >> x >> y >> s;
    if(x % y * n > s) {
        std::cout << "NO\n";
        return ;
    }
    s -= x % y * n;
    if(s % y != 0) {
        std::cout << "NO\n";
        return ;
    }
    s /= y;
    int begin = x / y;
    int num = -1;
    for(int i = 1; i <= n; ++i) {
        int sum = i * (begin + begin + i - 1) / 2;
        if(sum > s) break;
        if(dp[s - sum] <= n - i) {
            num = i;
            break;
        }
    }
    if(num == -1) {
        std::cout << "NO\n";
        return ;
    }
    std::vector<int> ans;
    for(int i = 0; i < num; ++i) ans.push_back(x + i * y);
    num = s - num * (begin + begin + num - 1) / 2;
    while(num != 0) {
        for(int i = 0; i < p[num][0]; ++i) ans.push_back(i * y + x % y);
        num = p[num][1];
    }
    while(ans.size() < n) ans.push_back(x % y);
    std::cout << "YES\n";
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}