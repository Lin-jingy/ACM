#include<bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int ans = 0;
    for(int i = 0; i < n; ){
        if(s[i] == 'B') {
            ++ans;
            i += k;
        }else ++i;
    }
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