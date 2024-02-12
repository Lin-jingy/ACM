#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string a, b;
    std::cin >> a >> b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int k1 = a[1] - a[0];
    int k2 = b[1] - b[0];
    k1 = std::min(k1, 5 - k1);
    k2 = std::min(k2, 5 - k2);

    if (k1 == k2)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}
