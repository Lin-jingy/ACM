#include <bits/stdc++.h>

#define int long long
constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;

int dp[N][2];

constexpr int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    s = ' ' + s;
    int ans = 0;
    constexpr int M2 = qpow(2, mod - 2);
    dp[0][0] = dp[0][1] = M2;

    for(int i = 1; i < s.size(); ++i) {
        int sum = qpow((dp[i - 1][1] + dp[i - 1][0] * 2) % mod, mod - 2);
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) * sum % mod;
        dp[i][1] = dp[i - 1][0];
    }
    

    return 0;
}