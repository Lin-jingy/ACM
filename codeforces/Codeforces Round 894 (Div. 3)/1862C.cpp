#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];

    int r = n;
    for(int i = 1; i <= n; ++i) {
        while(a[r] < i) --r;
        if(r < 1) goto A;
        if(a[i] != r) goto A;

    }
    std::cout << "YES\n";
    return ;
    A:;
    std::cout << "NO\n";

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
