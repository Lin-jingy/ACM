#include <bits/stdc++.h>

#define int long long
constexpr int mod = 998244353;
constexpr int N = 5e5 + 5;
int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

int C(int n,int m) {
    int res = 1;
    for(int i = 0; i < m; i++) res = res * (n - i) % mod;
    for(int i = 0; i < m; i++) res = res * qpow(i + 1, mod - 2) % mod;
    return res;
};

void solve() {
    int n, mx;
    std::cin >> n >> mx;
    std::vector<std::array<int, 3>> v(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    std::vector<int> list = {1};
    auto dfs = [&](auto &&self, int p) ->void{
        if(p == -1) return ;
        self(self, v[p][0]);
        list.push_back(v[p][2]);
        self(self, v[p][1]);
    };
    dfs(dfs, 1);
    list.push_back(mx);
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        if(list[i] == -1) {
			int l = i, r = i;
			while(list[i] == -1) r = i, ++i;
			int d = list[r + 1] - list[l - 1];
			ans = ans * C(r - l + 1 + d,r - l + 1) % mod;
		}
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}