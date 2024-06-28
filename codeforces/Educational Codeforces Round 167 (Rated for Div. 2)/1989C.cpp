#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < n; ++i) std::cin >> b[i];
    int add = 0, dec = 0;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == b[i] and a[i] == 1) add++;
        else if(a[i] == b[i] and a[i] == -1) dec++;
        else if(a[i] == 1 and b[i] != 1) ans1++;
        else if(a[i] != 1 and b[i] == 1) ans2++;
    }

    while(add--) {
        if(ans1 > ans2) ++ans2;
        else ++ans1;
    }

    while(dec--) {
        if(ans1 > ans2) --ans1;
        else --ans2;
    }

    std::cout << std::min(ans1, ans2) << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}