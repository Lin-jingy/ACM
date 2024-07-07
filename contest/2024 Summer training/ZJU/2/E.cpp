#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), v;
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::ranges::sort(a);
    v = a;
    k -= std::accumulate(a.begin(), a.end(), 0LL);
    std::vector<int> num;
    while(k > 0) {
        while(k < v.back()) v.pop_back();
        num.push_back(v.back());
        k -= v.back();
    } 
    std::ranges::reverse(num);
    for(int i = a.size() - 2; i >= 0; --i) {
        if(num.empty()) break;
        if(a[i] < num.back()) a[i] = num.back(), num.pop_back();
    }
    
    for(int i = 0; i < n; ++i) std::cout << a[i] << ' ';
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}