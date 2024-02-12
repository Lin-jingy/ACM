#include<bits/stdc++.h>

void solve(){
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a + b == c) std::cout << "+\n";
    else std::cout << "-\n";

}
signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--)solve();
    return 0;
}