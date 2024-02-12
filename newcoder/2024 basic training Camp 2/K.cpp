#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int n;
std::string s;
int y;
std::unordered_set<int> set;
void check(const std::string &p) {
    int x = 0;
    for (auto i : p) {
        x *= 10;
        x += i - '0';
    }
    if (x == 0 && p.size() == 1) set.insert(0);
    if (p[0] == '0' || x > y || x % 8 != 0) return;
    set.insert(x);
}

void solve() {
    set.clear();
    int ans = 0;
    std::cin >> n >> s >> y;
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            if (a == b) continue;
            for (int c = 0; c <= 9; ++c) {
                if (a == c || b == c) continue;
                for (int d = 0; d <= 9; ++d) {
                    if (a == d || b == d || c == d) continue;
                    for (int _ = 0; _ <= 9; ++_) {
                        std::string p = s;
                        for (auto &i : p) {
                            if (i == 'a') i = a + '0';
                            if (i == 'b') i = b + '0';
                            if (i == 'c') i = c + '0';
                            if (i == 'd') i = d + '0';
                            if (i == '_') i = _ + '0';
                        }
                        check(p);
                    }
                }
            }
        }
    }
    // for (auto i : set) std::cout << i << ' ';
    std::cout << set.size() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
