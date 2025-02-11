#include <bits/stdc++.h>

constexpr bool MultiTest = false;

class Solution {
   private:
    unsigned n, m, ans = 0;
    std::vector<std::pair<std::string, std::bitset<32>>> data;

   public:
    Solution() {}

    void clear() {}

    void input() {
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            std::string s;
            int x;
            std::cin >> s >> x;
            data.emplace_back(s, x);
        }
    }

    int get(int pos, int x) {
        for (const auto &[str, num] : data) {
            if (str == "AND") x &= num[pos];
            else if (str == "OR") x |= num[pos];
            else x ^= num[pos];
        }
        return x;
    }

    void solve() {
        for (int i = 31; i >= 0; --i) {
            int c0 = get(i, 0);
            int c1 = get(i, 1);
            if ((ans | (1 << i)) <= m && c1 > c0) ans |= 1 << i;
        }
        for (const auto &[str, num] : data) {
            if (str == "AND") ans &= num.to_ulong();
            else if (str == "OR") ans |= num.to_ulong();
            else ans ^= num.to_ulong();
        }
    }
    void output() { std::cout << ans << '\n'; }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    Solution S;
    int T = 1;
    if constexpr (MultiTest) std::cin >> T;
    while (T--) {
        S.input();
        S.solve();
        S.output();
        S.clear();
    }
}