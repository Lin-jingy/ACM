#include <iostream>
#include <string>
#include <vector>
inline int lowbit(int x) { return x & (-x); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) {
        int n, ans = 0;
        std::string s;
        std::cin >> n >> s;
        s = ' ' + s;
        std::vector<int> k(n + 1);
        for (int i = 1; i <= n; i++)
            if (s[i] == '1' && i + lowbit(i) <= n) k[i + lowbit(i)]++;
        for (int i = 1; i <= n; i++)
            if (s[i] - '0' + k[i] == 1) ans++;
        std::cout << ans << '\n';
    }
    return 0;
}