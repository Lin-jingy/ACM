#include<bits/stdc++.h>

int a[3][3];

void solve() {
    int n, m;
    std::cin >> n >> m;
    bool ok = false;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[1][1] >> a[1][2] >> a[2][1] >> a[2][2]; 
        if(a[1][2] == a[2][1]) ok = 1;
    }  
    if(m % 2 != 0 or !ok) {
        std::cout << "NO\n";
        return ;
    }
    std::cout << "YES\n";


    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}