#include <bits/stdc++.h>

int N;

void print(std::vector<std::vector<int>> &v) {
    for(int i = 1; i < v.size(); ++i) {
        for(int j = 1; j < v[i].size(); ++j) {
            // std::cout << v[i][j] << ' ';
            printf("%4d", v[i][j]);
        }
        // std::cout << '\n';
        printf("\n");
    }
}
void dfs(std::vector<std::vector<int>> &v, int n) {
    if(n == 2) {
        v[1][1] = 1;
        v[1][2] = 3;
        v[2][1] = 4;
        v[2][2] = 2;
        return ;
    }
    dfs(v, n / 2);
    int k = n / 2;
    int rk = k / 2;
    if(n != N) {
        for(int i = k + 1; i <= n; ++i) 
            for(int j = 1; j <= k; ++j) 
                v[i][j] = v[i - k][j] + n;
        for(int i = 1; i <= k; ++i) 
            for(int j = k + 1; j <= n; ++j) 
                v[i][j] = v[n - i + 1][j - k];
        for(int i = k + 1; i <= n; ++i) 
            for(int j = k + 1; j <= n; ++j) 
                v[i][j] = v[k - (i - k) + 1][j - k];
    } else {
        //右下
        for(int i = k + 1; i <= n; ++i) 
            for(int j = k + 1; j <= n; ++j)
                v[i][j] = v[i - k][j - k];
        for(int i = k + 1; i <= rk; ++i) 
            for(int j = k + 1; j <= n; ++j)
                std::swap(v[i][j], v[i + rk][j]);
        //左下
        for(int i = k + 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j) 
                v[i][j] = v[i - k][j];
        for(int i = k + 1; i <= rk; ++i)
            for(int j = 1; j <= k; ++j)
                std::swap(v[i][j], v[i + rk][j]);
        for(int i = k + 1; i <= n; ++i) 
            for(int j = 1; j <= rk; ++j)
                std::swap(v[i][j], v[i][j + rk]);

        //右上
        for(int i = 1; i <= k; ++i)
            for(int j = k + 1; j <= n; ++j)
                v[i][j] = v[i][j - k];
        for(int i = 1; i <= k; i += rk)
            for(int j = k + 1; j <= k; ++j)
                std::swap(v[i][j], v[i + rk][j]);
        for(int i = 1; i <= k; ++i)
            for(int j = k; j <= k + rk; ++j)
                std::swap(v[i][j], v[i][j + rk]);
    }
    
}

void solve() {
    freopen("1.out", "w", stdout);
    int n;
    std::cin >> n;
    N = n;
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1));
    if(n % 2 == 1) {
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) v[i][j - i + 1] = j;
            for(int j = n - i + 2; j <= n; ++j) v[i][j] = j - (n - i + 2) + 1;
        }
        print(v);
    } else {
        if(n % 4 != 0) std::cout << -1 << '\n';
        else {
            dfs(v, n);
            print(v);
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}