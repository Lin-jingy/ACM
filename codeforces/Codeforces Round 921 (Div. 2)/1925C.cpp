#if __GNUC__
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#else
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define and &&
#define or ||
#endif

#if _WIN64 && __GNUC__
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif
#if _WIN64 && __GNUC__
using int128 = __int128;
#endif

using PII = std::pair<int, int>;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;

void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, k, m;
    std::cin >> n >> k >> m;
    std::string s;
    std::cin >> s;
    int num = 0;
    std::unordered_set<char> st;
    std::vector<char> ans;
    for (auto i : s) {
        st.insert(i);
        if (st.size() == k) ++num, st.clear(), ans.eb(i);
    }
    if (num >= n) {
        std::cout << "YES\n";
    } else {
        char ch;
        for (ch = 'a'; ch <= 'a' + k - 1; ++ch) {
            if (!st.count(ch)) break;
        }
        while (ans.size() > n) ans.pop_back();
        while (ans.size() < n) ans.eb(ch);
        std::cout << "NO\n";
        for (auto i : ans) std::cout << i;
        std::cout << '\n';
    }
}