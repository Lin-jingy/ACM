#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int t0 = std::count(s.begin(), s.end(), '0');
    int t1 = s.size() - t0;
    if(t0 == t1) {
        std::cout << 0 << '\n';
        return;
    }
    for (auto i:s) {
        if(i == '1') {
            if(!t0)
                break;
            t0--;
        }else {
            if(!t1)
                break;
            t1--;
        }
    }
    std::cout << t0 + t1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
