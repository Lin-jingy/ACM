#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];

    long long ans = 0;
    for(auto i:a) {
        ans ++;
        if(i == ans) ++ans;
    }

    std::cout << ans << '\n';


    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}