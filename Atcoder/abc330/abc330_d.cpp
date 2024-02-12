#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(auto &i:v) std::cin >> i;
    std::vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(v[i][j] == 'o') l[i]++, r[j]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(v[i][j] == 'o') {
                ans += (l[i] - 1) * (r[j] - 1);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
