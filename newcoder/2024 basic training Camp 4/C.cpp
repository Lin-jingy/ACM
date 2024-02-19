#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i) std::cin >> v[i];
    int p, q;
    std::cin >> p >> q;
    std::vector<std::pair<int, int>> opz;
    for(int i = 0; i < q; ++i) {
        int op, z;
        std::cin >> op >> z;
        --z;
        opz.push_back({op, z});
    }
    for(int i = 0; i < p; ++i) {
        for(auto [op, z] : opz) {
            if(op == 1) {
                char f = v[z][m - 1];
                for(int j = m - 2; j >= 0; --j) v[z][j + 1] = v[z][j];
                v[z][0] = f;
            } else {
                char f = v[n - 1][z];
                for(int j = n - 2; j >= 0; --j) v[j + 1][z] = v[j][z];
                v[0][z] = f;
            }
        }
    }
    std::cout << v[x - 1][y - 1] << '\n';
    
    return 0;
}