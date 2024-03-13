#include <bits/stdc++.h>

// #define int long long
template <class T>using vec = std::vector<T>;
template <class T>
std::istream& operator>>(std::istream& in, std::vector<T>& v) {
    for(auto &i : v) in >> i;
    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    for(auto i = v.begin(); i != v.end(); ++i) 
        out << *i << " \n"[i == v.end()];
    return out;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    long long ans = 0;
    for(int i = 0; i < 32; ++i) {
        int k = 0;
        for(int j = 0; j < n; ++j) {
            if((a[j] >> i) & 1) k = j - k + 1;
            ans += 1LL * k * (1 << i);
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
