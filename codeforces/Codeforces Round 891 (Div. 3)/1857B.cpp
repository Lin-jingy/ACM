#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    
    int w = 0;
    int k = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] + w >= '5') k = i, w = 1;
        else s[i] += w, w = 0;
    }
    for (int i = k; i < n; i++) s[i] = '0';
    if (w) s = '1' + s;
    std::cout << s << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}