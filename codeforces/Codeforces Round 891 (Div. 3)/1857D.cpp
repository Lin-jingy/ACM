#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n), b(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    for(int i = 0; i < n; ++i) std::cin >> b[i], a[i] -= b[i];
    int mx = INT_MIN;
    for(int i = 0; i < n; ++i) mx = std::max(mx, a[i]);
    std::vector<int>ans;
    for(int i = 0; i < n; ++i) if(mx == a[i]) ans.emplace_back(i + 1);
    std::cout << ans.size() << '\n';
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n'; 

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}