#include <bits/stdc++.h>


std::vector<std::vector<int>> v(2005);
constexpr int K = 2000, T = 500;
int f = 1;
void push(int line) {
    std::vector<std::vector<int>> a(T + 10, std::vector<int>(T + 10));
    for(int i = 1; i <= T; ++i) a[1][i] = f++;
    for(int i = 2; i <= T + 1; ++i) {
        for(int j = 1; j < i; ++j) a[i][j] = a[j][i - 1];
        for(int j = i; j <= T; ++j) a[i][j] = f++;
    }
    for(int i = line; i < line + T + 1; ++i) {
        for(int j = 1; j <= T; ++j) v[i].push_back(a[i - line + 1][j]);
    }
}
void push1(int line) {
    std::vector<std::vector<int>> a(T + 10, std::vector<int>(T + 10));
    for(int i = 1; i <= T; ++i) a[1][i] = v[line - 1][i - 1];
    for(int i = 2; i <= T + 1; ++i) {
        for(int j = 1; j < i; ++j) a[i][j] = a[j][i - 1];
        for(int j = i; j <= T; ++j) a[i][j] = f++;
    }
    for(int i = line; i < line + T + 1; ++i) {
        for(int j = 1; j <= T; ++j) v[i].push_back(a[i - line + 1][j]);
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("1.out", "w", stdout);
    int k, t;
    std::cin >> k >> t;
    push(0);
    for(int i = T; i < K; i += T) 
        push1(i);
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < t; ++j) {
            std::cout << v[i][j] << " \n"[j == t - 1];
        }
    }
    return 0;
}