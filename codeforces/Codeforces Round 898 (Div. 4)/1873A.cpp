#include<bits/stdc++.h>

void solve(){
    std::string s;
    std::cin >> s;
    if(s == "abc" or s == "bac" or s == "cba" or s == "acb") std::cout << "YES\n";
    else std::cout << "NO\n";

}

int main(){
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}