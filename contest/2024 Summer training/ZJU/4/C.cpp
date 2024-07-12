#include <bits/stdc++.h>

#define int long long 
int n, m, p, b;
// std::unordered_set<int> s;
constexpr int N = 1e6 + 10;
int s[N], next[N];
// int print[105][105];

// std::vector<int> k;
// int dfs(int last, int j) {
//     if(s.count(last)) return k[last] = 1;
//     if(last == 0) return k[last] = 0;
//     if(k[last] != -1) return k[last];
//     for(int i = 1; i <= std::min(last, j); ++i) {
//         if(dfs(last - i, j) == 0) return k[last] = 1;
//     }
//     return k[last] = 0;
// }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m >> p >> b;
    for(int i = 1, x; i <= m; ++i) std::cin >> x, s[x] = 1;
    // k.assign(n + 1, -1);

    // for(int j = 1; j <= n; ++j) {
    //     k.assign(n + 1, -1);
    //     for(int last = 1; last <= n; ++last) {
    //         print[j][last] = dfs(last, j);
    //     }
    // }
    // for(int j = 1; j <= n; ++j) {
    //     // std::cout << std::format("j={}: ", j);
    //     printf("j=%3d:", j);
    //     for(int last = 1; last <= n; ++last) {
    //         // std::cout << print[j][last] << ' ';
    //         printf("%2d ", print[j][last]);
    //     }
    //     std::cout << '\n';
    // }

    int ans = 0;
    next[n + 1] = n + 1;
    for(int i = n; i >= 1; --i) {
        next[i] = next[i + 1];
        if(!s[i]) next[i] = i;
    }
    for(int i = 1; i <= n; ++i) ans += p ^ i;
    for(int i = 1; i <= n; ++i) {
        int k = ans;
        for(int j = i + 1; j <= n; j += i + 1) {
            j = next[j];
            if(j > n) break;
            k += (b ^ j) - (p ^ j);
        }
        std::cout << k << ' ';
    }
    return 0;
}