#include<bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    for(int i = 1; i < n; ++i) {
        a[i] = a[i - 1];
        if(s[i] == s[i - 1]) ++a[i];
    }
    while(q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << a[r - 1] - a[l - 1] << '\n';
    }


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