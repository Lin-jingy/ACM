#include <bits/stdc++.h>

#define LOCAL 0
#if LOCAL
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
#define int long long
using PII = std::pair<int, int>;
using i128 = __int128;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
#define push_back(x) eb(std::move(x))
using vec = std::vector<int>;
void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while (T--) solve();
    return 0;
}

std::map<int, int> mp;
vec pos(100005);

class SegmentTree {
private:
    std::vector<int> a;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void pushUp(int p) {
        f[p] = std::max(f[ls(p)], f[rs(p)]);
    }

public:
    vec f;
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        f.assign(n << 4, {});
    }
    void Set(int p, int l, int r, int d, int x) {
        if(l == r) {
            f[p] = x;
            return ;
        }
        int mid = l + r >> 1;
        if(d <= mid) Set(ls(p), l, mid, d, x);
        else Set(rs(p), mid + 1, r, d, x);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f[p];
        int mid = l + r >> 1, sum = 0;
        if (i <= mid) sum = query(ls(p), l, mid, i, j);
        if (j > mid) sum = std::max(sum, query(rs(p), mid + 1, r, i, j));
        return sum;
    }
};

void solve() {
    int n, d;
    std::cin >> n >> d;
    vec a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], mp[a[i]] = 1;
    int f = 1;
    for(auto &i:mp) i.second = f, pos[f++] = i.first;
    SegmentTree T(n + 1);
    int ans = 1;
    vec dp(n + 1);
    vec k;
    for(int i = 1; i <= n; ++i) {
        auto l = mp.upper_bound(a[i] - d);
        auto r = mp.lower_bound(a[i] + d);
        if(l == mp.begin()) {
            dp[i] = 1;
        } else {
            --l;
            dp[i] = T.query(1, 1, n, 1, l->second) + 1;
        }
        if(r != mp.end()) {
            dp[i] = std::max(dp[i], T.query(1, 1, n, r->second, n) + 1);
        }
        T.Set(1, 1, n, mp[a[i]], dp[i]);
        ans = std::max(ans, dp[i]);
    }
    //std::cout << ans << '\n';
    int val = 0;
    for(int i = n; i >= 1; --i) if(dp[i] == ans) {
        val = a[i] + d;
        break;
    }
    for(int i = n; i >= 1; --i) {
        if(dp[i] == ans and abs(val - a[i]) >= d) --ans, k.eb(i), val = a[i];
    }
    std::reverse(All(k));
    std::cout << k.size() << '\n';
    for(auto i:k) std::cout << i << ' ';
    std::cout << '\n';
}

// #include <bits/stdc++.h>

// #define LOCAL 0
// #if LOCAL
// #define dbg(x...)                  \
//     do {                           \
//         std::cout << #x << " -> "; \
//         err(x);                    \
//     } while (0)

// void err() {
//     std::cout << std::endl
//               << std::endl;
// }

// template <class T, class... Ts>
// void err(T arg, Ts... args) {
//     std::cout << std::fixed << std::setprecision(10) << arg << ' ';
//     err(args...);
// }
// #else
// #define dbg(...)
// #endif
// #define int long long
// using PII = std::pair<int, int>;
// using i128 = __int128;
// #define All(x) x.begin(), x.end()
// #define eb(x) emplace_back(x)
// #define push_back(x) eb(std::move(x))
// using vec = std::vector<int>;
// void solve();

// signed main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     int T = 1;
//     //std::cin >> T;
//     while (T--) solve();
//     return 0;
// }

// void solve() {
//     int n, d;
//     std::cin >> n >> d;
//     std::vector<int> a(n + 1), dp(n + 1);
//     int mx = 1;
//     std::vector<int> p(n + 1);
//     for (int i = 1; i <= n; i++){
//         std::cin >> a[i];
//         dp[i] = 1;
//         for (int j = std::max(1ll, i - 1000); j < i; j++) {
//             if (abs(a[j] - a[i]) >= d and dp[j] + 1 > dp[i]) {
//                 dp[i] = dp[j] + 1;
//                 p[i] = j;
//             }
//             if (dp[i] > dp[mx]) mx = i;
//         }
//     }
//     std::vector<int> ans;
//     int T = p[mx];
//     ans.emplace_back(mx);
//     while (T) ans.push_back(T), T = p[T];
//     std::reverse(ans.begin(), ans.end());
//     std::cout << ans.size() << '\n';
//     for(auto i:ans) std::cout << i << ' ';
// }