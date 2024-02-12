#include<bits/stdc++.h>

int main(){
    int T;
    std::cin >> T;
    while(T--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << (std::abs(a - b) + 2 * c - 1) / (2 * c) << "\n";
    }
    return 0;
}