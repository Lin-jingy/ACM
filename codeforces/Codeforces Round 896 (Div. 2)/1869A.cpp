#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    for(int i = 0, x; i < n; ++i) std::cin >> x;
    if(n % 2 == 0){
        std::cout << 2 << '\n';
        std::cout << 1 << ' ' << n << '\n';
        std::cout << 1 << ' ' << n << '\n';
    }else{
        std::cout << 4 << '\n';
        std::cout << 1 << ' ' << n << '\n';
        std::cout << 2 << ' ' << n << '\n';
        std::cout << 1 << ' ' << 2 << '\n';
        std::cout << 1 << ' ' << 2 << '\n';
    }

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}