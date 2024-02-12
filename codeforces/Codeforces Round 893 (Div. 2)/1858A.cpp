#include<bits/stdc++.h>

void solve(){
    int a, b, c;
    std::cin >> a >> b >> c;
    a += c % 2;
    if(a > b) std::cout << "First\n";
    else std::cout << "Second\n";

}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while(_--)solve();
    return 0;
}
