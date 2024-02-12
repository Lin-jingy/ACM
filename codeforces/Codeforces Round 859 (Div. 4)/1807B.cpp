#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;  
    int k[2] = {0, 0};
    for(int i = 0, x; i < n; ++i){
        std::cin >> x;
        k[x % 2] += x;
    }
    if(k[0] > k[1]) std::cout << "YES\n";
    else std::cout << "NO\n";

}
signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--)solve();
    return 0;
}