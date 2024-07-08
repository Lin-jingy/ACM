#include <bits/stdc++.h>

void print(std::vector<std::vector<int>> &v) {
    for(int i = 1; i < v.size(); ++i) {
        for(int j = 1; j < v[i].size(); ++j) {
            std::cout << v[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
void check(std::vector<std::vector<int>> &v) {
    for(int i = 1; i < v.size(); ++i) {
        std::set<int> s1;
        std::set<int> s2;
        for(int j = 1; j < v.front().size(); ++j) 
            s1.insert(v[i][j]),
            s2.insert(v[j][i]);
        assert(s1.size() == v.size() - 1);
        assert(s2.size() == v.size() - 1);
    }
}
void solve() {
    int n;
    std::cin >> n;
    if(n == 2) {
        std::cout << -1 << '\n';
        return ;
    }
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1));
    int N = n;
    if(n % 2 == 0) --N;
    for(int i = 1; i <= N; ++i) {
        for(int j = i; j <= N; ++j) v[i][j - i + 1] = j;
        for(int j = N - i + 2; j <= N; ++j) v[i][j] = j - (N - i + 2) + 1;
    }
    if(n % 2 == 0) {
        for(int i = 2; i <= N; ++i) v[i][i - 1] = n;
        v[1][N] = n;
        for(int i = 1; i <= N; ++i) {
            std::set<int> s;
            for(int j = 1; j <= n; ++j) s.insert(j);
            for(int j = 1; j <= N; ++j) s.erase(v[i][j]);
            v[i][n] = *s.begin();
        }
        for(int i = 1; i <= N; ++i) {
            std::set<int> s;
            for(int j = 1; j <= n; ++j) s.insert(j);
            for(int j = 1; j <= N; ++j) s.erase(v[j][i]);
            v[n][i] = *s.begin();
        }
        v[n][n] = n;
    }
    // check(v);
    print(v);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}