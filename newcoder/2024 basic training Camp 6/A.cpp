#include <bits/stdc++.h>


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int l, r;
    std::cin >> l >> r;
    std::set<int> s;
    std::vector<int> v = {2, 3, 5, 7, 11, 13, 17};
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v.size(); ++j) {
            for(int k = 0; k < v.size(); ++k) {
                if(i != j and j != k and i != k) {
                    s.insert(v[i] * v[j] * v[k]);
                }
            }
        }
    }
    for(int i = l; i <= r; ++i) {
        if(s.count(i)) {
            std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << "-1\n";
    return 0;
}