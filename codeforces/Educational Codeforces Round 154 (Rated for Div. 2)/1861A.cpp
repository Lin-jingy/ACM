#include<bits/stdc++.h>

void solve(){
    std::string s;
    std::cin >> s;
    for(auto i:s) if(i == '1' or i == '3') std::cout << i;
    std::cout << "\n";
}

int main(){
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}