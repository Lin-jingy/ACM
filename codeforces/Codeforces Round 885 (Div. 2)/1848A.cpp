#include<bits/stdc++.h>

void solve(){
    int n, m, k, x, y, a, b, flag = 0;
    std::cin >> n >> m >> k >> x >> y;
    while(k--){
        std::cin >> a >> b;
        if((a + b + x + y) % 2 == 0) flag = 1;
    }
    std::cout << (!flag ? "YES\n" : "NO\n");
    
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}