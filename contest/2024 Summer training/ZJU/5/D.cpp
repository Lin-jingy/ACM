#include <bits/stdc++.h>

#define int long long 
signed ans[300005];
int f = 0;

int n;
void print(int size) {
    assert(size <= 3 * n);
    std::cout << size << '\n';
    for(int i = 1; i <= size; ++i) std::cout << ans[i] << ' ';
    std::cout << '\n';
}

void solve() {
    f = 0;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int begin = 1;
    while(begin <= n and a[begin] == 0) ++begin;
    if(begin == n + 1) {
        std::cout << 0 << '\n';
        return ;
    }
    int k = n;
    while(k--) ans[++f] = begin;
    int add = a[begin] * n;
    auto b = a;
    for(int i = begin + 1; i <= n; ++i) a[i] += add;
    for(int i = n - 1; i >= begin; --i) ans[++f] = i;
    print(f);

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("1.in", "r", stdin);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}