#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long
constexpr int p = 1331;
constexpr int N = 1e5 + 5;
using ull = unsigned long long;
ull la[N], ra[N], lb[N], rb[N], base[N];
int n, m;

ull get_hash(ull* p, int l, int r, int op) {
    if (op == 1) return p[r] - p[l - 1] * base[r - l + 1];
    else if (op == 2) return p[l] - p[r + 1] * base[(n - l + 1) - (n - r + 1) + 1];
    else return p[l] - p[r + 1] * base[(m - l + 1) - (m - r + 1) + 1];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    if (a.front() != b.back() || a.back() != b.front()) {
        std::cout << "-1\n";
        return 0;
    }
    a = ' ' + a;
    b = ' ' + b;

    // hash
    for (int i = 1; i <= n; ++i) la[i] = la[i - 1] * p + a[i];
    for (int i = n; i >= 1; --i) ra[i] = ra[i + 1] * p + a[i];
    for (int i = 1; i <= m; ++i) lb[i] = lb[i - 1] * p + b[i];
    for (int i = m; i >= 1; --i) rb[i] = rb[i + 1] * p + b[i];
    base[0] = 1;
    for (int i = 1; i <= std::max(n, m); ++i) base[i] = base[i - 1] * p;
    //---------

    std::vector<int> al, bl;
    for (int i = 1; i <= std::min(n, m); ++i) {
        if (get_hash(la, 1, i, 1) == get_hash(ra, 1, i, 2)) al.push_back(i);
        if (a[i] != b[m - i + 1]) break;
    }

    int l = 0;
    for (int i = 1; i <= std::min(n, m); ++i) {
        if (get_hash(lb, 1, i, 1) == get_hash(rb, 1, i, 3)) bl.push_back(i);
        if (b[i] != a[n - i + 1]) break;
    }

    int ans = 0;
    int len = std::min(n, m);
    for (int i = 0; i < al.size(); ++i) {
        auto it = std::upper_bound(bl.begin(), bl.end(), len - al[i]);
        if (it == bl.begin()) continue;
        --it;
        ans = std::max(ans, *it + al[i]);
    }
    std::cout << ans * 2 << '\n';

    return 0;
}
