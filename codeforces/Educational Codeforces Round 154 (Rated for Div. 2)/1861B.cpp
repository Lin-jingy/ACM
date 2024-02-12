#include<bits/stdc++.h>

void solve(){
    std::string a, b;
    std::cin >> a >> b;
    if(a.size() == 2 or a == b) {
        std::cout << "YES\n";
        return ;
    }
    for(int i = 1; i < a.size(); ++i){
        if(a[i] == b[i] and a[i] == '1' and a[i - 1] == b[i - 1] and a[i - 1] == '0'){
            std::cout << "YES\n";
            return ;
        }
    }
    std::cout << "NO\n";
    return ;
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}