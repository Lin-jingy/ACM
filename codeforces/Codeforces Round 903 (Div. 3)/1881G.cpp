#include <bits/stdc++.h>

int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector<std::array<char, 5>> v(n << 2);
    std::vector<int> f(n << 2), tag(n << 2);
    auto pushUp = [&](int p) {
        f[p] = f[ls(p)] | f[rs(p)];
        if(v[ls(p)][4] == v[rs(p)][1]) f[p] = 1;
        if(v[ls(p)][3] and v[ls(p)][3] == v[rs(p)][1]) f[p] = 1;
        if(v[rs(p)][2] and v[rs(p)][2] == v[ls(p)][4]) f[p] = 1;
    };
    auto pushDown = [&](int p, int d) {
        if(!tag[p]) return ;
        tag[ls(p)] = (tag[ls(p)] + d) % 26;
        tag[rs(p)] = (tag[rs(p)] + d) % 26;
        tag[p] = 0;
        for(int i = 1; i <= 4; ++i) v[ls(p)][i] = (v[ls(p)][i] - 'a' + d) % 26 + 'a';
        for(int i = 1; i <= 4; ++i) v[rs(p)][i] = (v[rs(p)][i] - 'a' + d) % 26 + 'a';
    };
    auto build = [&](auto &&self, int p, int l, int r) {
        if(l == r) {
            v[p][1] = v[p][4] = s[l];
            return;
        }
        int mid = (l + r) >> 1;
        self(self, ls(p), l, mid);
        self(self, rs(p), mid + 1, r);
        pushUp(p);
    };
    auto update = [&](auto &&self, int p, int l, int r, int i, int j, int d) {
        if(i <= l and j >= r) {
            for(int i = 1; i <= 4; ++i) v[ls(p)][i] = (v[ls(p)][i] - 'a' + d) % 26 + 'a';
            for(int i = 1; i <= 4; ++i) v[rs(p)][i] = (v[rs(p)][i] - 'a' + d) % 26 + 'a';
            tag[p] = d;
            return ;
        }
        pushDown(p, d);
        int mid = (l + r) >> 1;
        if(i <= mid) self(self, ls(p), l, mid, i, j, d);
        else self(self, rs(p), mid + 1, r, i, j, d);
    };
    auto query = [&](auto &&self, int p, int l, int r, int i, int j) ->std::tuple<std::array<char, 5>, int> {
        if(i <= l and j >= r) {
            return std::tuple<std::array<char, 5>, int>(v[p], f[p]);
        }
        pushDown(p, 0);
        int mid = (l + r) >> 1;
        if(j <= mid) return self(self, ls(p), l, mid, i, j);
        else if(i > mid) return self(self, rs(p), mid + 1, r, i, j);
        else {
            std::tuple<std::array<char, 5>, int> L, R;
            L = self(self, ls(p), l, mid, i, j);
            R = self(self, rs(p), mid + 1, r, i, j);

        }
    };
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}