#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> a(n);
        for (auto &i : a) std::cin >> i.first;
        for (auto &i : a) std::cin >> i.second;
        std::ranges::sort(a);
        for (auto i : a) std::cout << i.first << ' ';
        std::cout << '\n';
        for (auto i : a) std::cout << i.second << ' ';
        std::cout << '\n';
    }
}