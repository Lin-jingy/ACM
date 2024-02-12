#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    long long sum = 0, cnt = 0;
    for(int i = 1, x; i <= n; ++i) {
        std::cin >> x;
        if(x == 1) ++cnt;
        else sum += x - 1;
    }
    if(sum >= cnt and n != 1) std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}