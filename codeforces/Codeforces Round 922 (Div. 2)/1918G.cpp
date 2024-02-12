#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// std::vector<int> ans;
// int n = 4;
// void dfs(int pos) {
//     if (pos == n) {
//         std::vector<int> b, c = ans;
//         b.push_back(ans[1]);
//         b.push_back(ans[ans.size() - 2]);
//         for (int i = 1; i <= ans.size() - 2; ++i) b.push_back(ans[i - 1] + ans[i + 1]);
//         std::sort(b.begin(), b.end());
//         std::sort(c.begin(), c.end());
//         for (int i = 0; i < b.size(); ++i) {
//             if (b[i] != c[i]) return;
//         }
//         for (auto i : ans) std::cout << i << ' ';
//         std::cout << '\n';
//         return;
//     }
//     for (int i = -5; i <= 5; ++i) {
//         if (i == 0) continue;
//         ans.push_back(i);
//         dfs(pos + 1);
//         ans.pop_back();
//     }
// }
int main() {
    // dfs(0);
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "YES\n";
        std::array<int, 6> a = {-2, -1, 1, -1, 1, 2};
        for (int i = 0; i < n; i++) std::cout << a[i % 6] << " \n"[i == n - 1];
    } else if (n < 7) {
        std::cout << "NO\n";
    } else {
        std::vector<int> a = {-3, -3, 2, 1, -1, 1, -2};
        while (a.size() < n) {
            for (int i = -3; i <= 3; ++i) {
                if (i == 0) continue;
                for (int j = -3; j <= 3; ++j) {
                    if (j == 0) continue;
                    if ((i == a[a.size() - 2] + j && a[a.size() - 2] == a.back() + i) || (i == a.back() + i && a[a.size() - 2] == a[a.size() - 2] + j)) {
                        a.push_back(j);
                        a.push_back(i);
                        goto A;
                    }
                }
            }
        A:;
        }
        std::cout << "YES\n";
        for (auto i : a) std::cout << i << ' ';
        std::cout << '\n';
    }
}
