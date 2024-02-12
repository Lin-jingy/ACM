#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using PII = std::pair<int, int>;
#define int long long

__gnu_pbds::tree<PII, __gnu_pbds::null_type, std::less<PII>,
                 __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    l, r;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 2; i <= n; ++i) r.insert({a[i], i});
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        l.insert({a[i - 1], i - 1});
        r.erase({a[i], i});
        ans += (l.order_of_key({a[i], 0})) * (n - i - r.order_of_key({a[i], 1e9}));
    }
    std::cout << ans << '\n';

    return 0;
}
