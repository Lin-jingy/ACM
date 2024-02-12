#include <bits/stdc++.h>

//#define int long long
const int inc = 131;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, m, a, b;
    std::cin >> m >> n >> a >> b;
    std::string s;
    std::vector<std::vector<unsigned>> hash(m + 1, std::vector<unsigned>(n + 1));
    std::unordered_set<unsigned> is;
    std::vector<unsigned> p(n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; ++i) p[i] = p[i - 1] * inc;
    for(int i = 1; i <= m; ++i) {
        std::cin >> s;
        s = ' ' + s;
        for(int j = 1; j <= n; ++j) hash[i][j] = hash[i][j - 1] * inc + s[j];
    }
    for(int i = 1; i <= m - a + 1; ++i) {
        for(int j = 1; j <= n - b + 1; ++j) {
            int end = j + b - 1;
            int c = 0;
            for(int k = i; k <= i + a - 1; ++k) {
                c += hash[k][end] - hash[k][j - 1] * p[end - j + 1];
                if(k == i + a - 1) is.insert(c);
                else c = c * p[b];
            }
        }
    }
    int q;
    std::cin >> q;

    while(q--) {
        int c = 0;
        for(int i = 0; i < a; ++i) {
            std::cin >> s;
            for(auto j:s) c = c * inc + j;
        }
        if(is.count(c)) std::cout << 1 << '\n';
        else std::cout << 0 << '\n';
    }


    return 0;
}
