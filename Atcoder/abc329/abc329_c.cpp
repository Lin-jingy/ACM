#include <bits/stdc++.h>

std::array<int, 26> p;
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0;
    int k = 1;
    p[s[0] - 'a'] = k;
    for(int i = 1; i < n; ++i) {
        if(s[i] == s[i - 1]) ++k;
        else k = 1;
        p[s[i] - 'a'] = std::max(p[s[i] - 'a'], k);
    }
    for(int i = 0; i < 26; ++i) ans += p[i];
    std::cout << ans << "\n";

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}
