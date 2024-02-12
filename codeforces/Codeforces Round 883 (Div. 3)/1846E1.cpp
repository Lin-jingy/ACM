#include<bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        for(int i(2); ; ++i) {
            int s = i * (i + 1) + 1;
            if(s > n) break;
            while(s < n){
                s = s * i + 1;
            }
            if(s == n){
                std::cout << "YES\n";
                goto A;
            }
        }
        std::cout << "NO\n";
        A:;
    }
}