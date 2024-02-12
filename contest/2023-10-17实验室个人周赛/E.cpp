#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s, mid, x;
    mid += "<3";
    for(int i = 0; i < n; ++i) {
        std::cin >> x;
        mid += x;
        mid += "<3";
    }
    std::cin >> s;
    int flag = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == mid[flag]) ++flag;
        if(flag >= mid.size()) {
            std::cout << "yes\n";
            return ;
        }
    }
    std::cout << "no\n";
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}