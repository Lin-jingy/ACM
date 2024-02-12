#include<bits/stdc++.h>
void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a == 1 and b == 1 and c == 0) {
        std::cout << "NO\n";
        return ;
    }
    if(a == 1) {
        if(b == c and c == 0) std::cout << "YES\n0\n";
        //else if(b == 2 and c == 0)std::cout << "YES\n2\n";
        else if(b == 1)  std::cout << "NO\n";
        else if(c == 0) std::cout << "YES\n" << b - 1 << '\n';
        else std::cout << "NO\n";
    }else {
        if(a > b + c) std::cout << "YES\n" << 2 * (b + c) + 1 << '\n';
        else std::cout << "NO\n";
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