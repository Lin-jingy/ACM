#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int a1, a2, a3, b1, b2, b3;
    std::cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int aa1 = a1, aa2 = a2, aa3 = a3, bb1 = b1, bb2 = b2, bb3 = b3;
    int mn = 0, mx = 0;
    mx = n - (a1 - std::min(a1, b2)) - (a2 - std::min(a2, b3)) - (a3 - std::min(a3, b1));
    mn = n - std::min(aa1, n - bb2) - std::min(aa2, n - bb3) - std::min(aa3, n - bb1);
    std::cout << mn << ' ' << mx << '\n';


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