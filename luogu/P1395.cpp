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
using vec = std::vector<int>;
void solve();

class Tree {
private:
    std::vector<std::vector<int>> *v;
    size_t size;

public:
    Tree(std::vector<std::vector<int>> *p) {
        v = p;
        size = p->size() - 1;
    }
    std::pair<int, int> GetCentroid() {
        std::pair<int, int> ans = {-1, -1};
        auto dfs = [&](auto dfs, int p, int fa) -> int {
            bool flag = true;
            int sum = 1;
            for (auto i : (*v)[p]) {
                if (i == fa) continue;
                int s = dfs(dfs, i, p);
                if (s > size / 2) flag = false;
                sum += s;
            }
            if (size - sum > size / 2) flag = false;
            if (flag) {
                if (ans.first == -1)
                    ans.first = p;
                else
                    ans.second = p;
            }
            return sum;
        };
        dfs(dfs, 1, 0);
        return ans;
    }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<vec> v(n + 1);
    for (int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        v[a].eb(b);
        v[b].eb(a);
    }
    Tree T(&v);
    std::pair<int, int> mid = T.GetCentroid();
    int p = mid.first;
    if (mid.second != -1) p = std::min(p, mid.second);
    int ans = 0;
    auto dfs = [&](auto dfs, int p, int fa) -> int {
        int sum = 0;
        for (auto i : v[p]) {
            if (i == fa) continue;
            sum += dfs(dfs, i, p);
        }
        ans += sum;
        return sum + 1;
    };
    dfs(dfs, p, 0);
    std::cout << p << ' ' << ans << '\n';
}