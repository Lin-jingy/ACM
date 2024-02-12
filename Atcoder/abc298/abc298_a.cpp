#include<bits/stdc++.h>

#define int long long 

void solve(){
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;
    int k1 = 0, k2 = 0;
    for(auto i : a){
        if(i == 'o')++ k1;
        if(i == 'x'){++ k2; break;}
    }
    if(k1 >= 1 and k2 == 0)std::cout << "Yes";
    else std::cout << "No";
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}