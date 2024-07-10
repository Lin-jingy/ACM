#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = 1e6 + 7, MOD = 998244353;
int n, tot;
pii op[N];
map<int, int> mp;
ll rmp[N];

void lsh() {
    set<int> s;
    for (int i = 1; i <= n; i++)
        if (op[i].first == 1)
            s.insert(op[i].second);
    for (auto x: s) {
        mp[x] = ++tot;
        rmp[tot] = x;
    }
}

class Bit {
private:
    ll arr[N];

    static int lowbit(int i) {
        return i & (-i);
    }

public:
    void add(int i, ll x) {
        while (i <= n) {
            arr[i] += x;
            i += lowbit(i);
        }
    }

    ll getPre(int i) {
        ll res = 0;
        while (i > 0) {
            res += arr[i];
            i -= lowbit(i);
        }
        return res;
    }

    ll getSum(int l, int r) {
        if (l > r) return 0;
        return getPre(r) - getPre(l - 1);
    }
} cnt, sum;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> op[i].first >> op[i].second;
    lsh();
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        auto [x, y] = op[i];
        if (x == 1) {
            cnt.add(mp[y], 1);
            sum.add(mp[y], y);
            s += y;
        } else {
            ll l = 1, r = s / y, res = 0;
            while (l <= r) {
                ll mid = (l + r) / 2;
                int id = (int) (lower_bound(rmp + 1, rmp + 1 + tot, mid) - rmp) - 1;
                ll tmp = sum.getPre(id) + mid * (cnt.getSum(id + 1, n) - y);
                if (tmp >= 0) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cout << res << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
    return 0;
}
