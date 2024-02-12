#include<bits/stdc++.h>

#define int long long
const int mod = 1e9 + 7;

int qpow(int a, int b) {
    int sum = 1;
    while(b > 0) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    s = ' ' + s;
    std::vector<std::array<int, 3>> dp(n + 1);
    int k = qpow(3, std::count(s.begin(), s.end(), '?'));
    int r3 = qpow(3, mod - 2);
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        if(s[i] == 'a') dp[i][0] = (dp[i][0] + k) % mod;
        else if(s[i] == 'b') dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
        else if(s[i] == 'c') dp[i][2] = (dp[i][2] + dp[i - 1][1]) % mod;
        else if(s[i] == '?') {
            dp[i][0] = (dp[i][0] + k * r3 % mod) % mod;
            dp[i][1] = (dp[i][1] + dp[i - 1][0] * r3 % mod) % mod;
            dp[i][2] = (dp[i][2] + dp[i - 1][1] * r3 % mod) % mod;
        }
    }
    std::cout << dp[n][2] << '\n' ;

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}