#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    int k[2] = {0, 0}, x;
    while(n--){
        std::cin >> x;
        k[x % 2]++;
    }
    if(k[1] == 0 or k[1] % 2 == 0) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}