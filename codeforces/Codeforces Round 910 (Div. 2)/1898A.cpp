#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int num = std::count(s.begin(), s.end(), 'B');
    if(num == k) std::cout << 0 << '\n';
    else if(num < k) {
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'A') ++num;
            if(num == k) {
                std::cout << 1 << '\n' << i + 1 << ' ' << 'B' << '\n';
                return ;
            }
        }
    }else {
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'B') --num;
            if(num == k) {
                std::cout << 1 << '\n' << i + 1 << ' ' << 'A' << '\n';
                return ;
            }
        }
    }


}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
