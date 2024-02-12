#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        p[x] = i;
    }
    int ans = n / 2;
    while (ans and p[ans] < p[ans + 1] and p[n - ans + 1] > p[n - ans]) --ans;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}