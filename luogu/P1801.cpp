#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;

using PII = std::pair<int, int>;
tree<PII, null_type, std::less<PII>, rb_tree_tag, tree_order_statistics_node_update> mp;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int m, n;
    std::cin >> m >> n;
    std::vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i) std::cin >> a[i];
    int i = 0;
    for (int j = 1; j <= n; ++j) {
        int x;
        std::cin >> x;
        while (i < x) {
            mp.insert({a[++i], i});
        }
        std::cout << mp.find_by_order(j - 1)->first << '\n';
    }
    return 0;
}
