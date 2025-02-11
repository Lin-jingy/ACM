#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, MAXN = 1e6;
int n, m, rt, cnt;
int son[MAXN][26], vis[MAXN], sum[N], tre[N], st[20][N], lg[N], ans[N];

struct query {
    int r, l, id;
    friend auto operator<=>(const query &a, const query &b) = default;
};

int lowbit(int x) { return x & (-x); }

void ins(int x, int val) {
    while (x <= n) {
        tre[x] += val;
        x += lowbit(x);
    }
}

int ask(int x) {
    int res = 0;
    while (x) {
        res += tre[x];
        x -= lowbit(x);
    }
    return res;
}

int modify(int &now, int tim) {
    if (!now) {
        now = ++cnt;
        ins(tim, 1);
        vis[now] = tim;
        return now;
    } else {
        ins(vis[now], -1);
        ins(tim, 1);
        vis[now] = tim;
        return now;
    }
}

template <class T>
class sparseTable {
   private:
    std::vector<std::vector<T>> ST;
    std::function<T(const T &, const T &)> _func;

   public:
    static T max(const T &t1, const T &t2) { return std::max(t1, t2); }
    static T min(const T &t1, const T &t2) { return std::min(t1, t2); }
    static T gcd(const T &t1, const T &t2) { return std::gcd(t1, t2); }

   public:
    sparseTable(const std::vector<T> &v, auto func) {
        _func = func;
        int len = v.size();
        int L1 = std::__lg(len) + 1;
        ST.assign(len, std::vector<T>(L1));
        for (int i = 0; i < len; ++i) ST[i][0] = v[i];

        for (int j = 1; j < L1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = func(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T operator()(int l, int r) const {
        int q = std::__lg(r - l + 1);
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    std::vector val(n + 1, 0);
    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        val[i] = s[i].size();
    }
    sparseTable st(val, sparseTable<int>::max);

    std::vector<query> q(m + 1);

    for (int i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    std::sort(q.begin() + 1, q.end());

    for (int i = 1, idx = 0; i <= m; i++) {
        while (idx < q[i].r) {
            ++idx;
            for (int j = 0, now = rt; j < val[idx]; j++) {
                now = modify(son[now][s[idx][j] - 'a'], idx);
            }
        }
        ans[q[i].id] = 2 * (ask(q[i].r) - ask(q[i].l - 1)) - st(q[i].l, q[i].r);
    }
    for (int i = 1; i <= m; i++) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}