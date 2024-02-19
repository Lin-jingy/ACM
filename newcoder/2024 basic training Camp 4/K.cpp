#include <bits/stdc++.h>

struct node {
    int X, add;
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    
    std::vector<int> Y;
    for(int i = 1; i <= n; ++i) if(s[i] == 'B') Y.push_back(i);

    auto dfs2 = [&](auto &&self, int l, int r) ->node {
        if(l == r) {
            if(s[l] == 'Y') return {0, 1};
            else return {2, 0};
        }
        int mid = (l + r) >> 1;
        node L = self(self, l, mid);
        node R = self(self, mid + 1, r);
        return {L.X * R.X, L.add * R.X + R.add};
    };
    auto dfs1 = [&](auto &&self, int l, int r) ->int {
        if(l == r) {
            int L = Y[l] + 1, R = Y[l + 1] - 1;
            if(R < L) return 1;
            node ans = dfs2(dfs2, L, R);
            return ans.X + ans.add;
        }
        int mid = (l + r) >> 1;
        return self(self, l, mid) + self(self, mid + 1, r);

    };

    while(q--) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int p;
            char c;
            std::cin >> p >> c;
            s[p] = c;
        } else {
            int l, r;
            std::cin >> l >> r;
            while(s[l] == 'R') ++l;
            if(l > r) {
                std::cout << 0 << '\n';
                continue;
            }
            
        }
    }

    return 0;
}