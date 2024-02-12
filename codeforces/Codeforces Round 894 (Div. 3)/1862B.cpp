#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> b;
    b.emplace_back(a[0]);
    for(int i = 1; i < n; ++i) {
        if(a[i] >= a[i - 1]) b.emplace_back(a[i]);
        else {
            b.emplace_back(a[i]);
            b.emplace_back(a[i]);
        }
    }

    std::cout << b.size() << '\n';
    for(auto i:b) std::cout << i << ' ';
    std::cout << '\n';
    return ;

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
