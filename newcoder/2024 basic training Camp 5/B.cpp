#include <bits/stdc++.h>

#define int long long
constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;
int f[N];


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    f[0] = 1, f[1] = 2;
    for(int i = 2; i < N; ++i) f[i] = (f[i - 2] + f[i - 1]) % mod;

    std::string s;
    std::cin >> s;

    int ans = 0;
    int n = s.size();
    s = ' ' + s;

    for(int i = 1; i <= n; ++i) {
        for(int j1 = 1; j1 <= 2; ++j1) {
            for(int j2 = 1; j2 <= 2; ++j2) {
                for(int j3 = 1; j3 <= 2; ++j3) {
                    if(i + j1 + j2 + j3 <= n and s[i] == 'm' and s[i + j1] == 'y' and s[i + j1 + j2] == 'g' and s[i + j1 + j2 + j3] == 'o') {
                        ans = (ans + f[i - 1] * f[n - i - j1 - j2 - j3] % mod) % mod;
                    }
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}