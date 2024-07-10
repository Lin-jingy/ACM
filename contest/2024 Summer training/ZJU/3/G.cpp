#include <bits/stdc++.h>

#define int long long
constexpr int N = 1e6 + 5;

class BIT {
#define lowb(x) ((-x) & x)
public:
    int n;
    int c[N];

    BIT() : n(N) {}

    void add(int i, int z) { for (; i <= n; i += lowb(i))c[i] += z; }

    int pre(int i) {
        int sum = 0;
        for (; i > 0; i -= lowb(i))sum += c[i];
        return sum;
    }

    int sum(int i, int j) { return pre(j) - pre(i - 1); }

#undef lowb
} sum, num;

typedef long long ll;
ll rmp[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<int, int> mp;
    std::vector<std::pair<int, int>> query(n);
    int Sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> query[i].first >> query[i].second;
        if (query[i].first == 1) mp[query[i].second]++;
    }
    int f = 1;
    for (auto &[i, j]: mp) {
        j = f;
        rmp[f] = i;
        f++;
    }

    for (auto [op, x]: query) {
        if (op == 1) {
            num.add(mp[x], 1);
            sum.add(mp[x], x);
            Sum += x;
        } else {
            int l = 0, r = Sum / x;
            int ans = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
//                auto it = mp.lower_bound(mid);
//                auto it1 = it;
//                int k1 = 0, k2 = 0;
//                if (it != mp.begin()) {
//                    --it;
//                    k1 = sum.sum(1, it->second);
//                }
//                if (it1 != mp.end() && it1->second < N) k2 = num.sum(it1->second, N - 1);
//                if (k1 / mid + k2 >= x) l = mid + 1, ans = mid;
//                else r = mid - 1;

                int it = std::lower_bound(rmp + 1, rmp + f, mid) - rmp;
                int k1 = 0, k2 = 0;
                if (it - 1 > 0) k1 = sum.pre(it - 1);
                if (it < f && it < N) k2 = num.sum(it, N - 1);
                if (k1 / mid + k2 >= x) l = mid + 1, ans = mid;
                else r = mid - 1;

//                std::cout << mid << ' ' << k1 << ' ' << k2 << '\n';
            }
            std::cout << ans << '\n';
        }
    }
    return 0;
}