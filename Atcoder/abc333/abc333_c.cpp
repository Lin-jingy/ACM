#include <bits/stdc++.h>

#define int long long

int fact(int k) {
    int sum = 0;
    while (k--)
        sum = sum * 10 + 1;
    return sum;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::set<int> s;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 1; j <= 13; ++j) {
            for (int k = 1; k <= 13; ++k) {
                s.insert(fact(i) + fact(j) + fact(k));
            }
        }
    }
    int i = 0;
    for (auto k : s) {
        i++;
        if (i == n) {
            std::cout << k << '\n';
            return 0;
        }
    }
    return 0;
}
