#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    int k = n / 2;
    std::vector<bool>p(n + 1);
    for(int i = n; i >= 1; --i){
        if(p[i]) continue;
        std::cout << i << ' ';
        if(i % 2 == 0){
            int x = i / 2;
            while(1) {
                std::cout << x << ' ';
                p[x] = true; 
                if(x % 2 == 1 or x < 1 or p[x / 2]) break;
                x /= 2;
            
            }
        }
        
    }
    std::cout << '\n';
}

int main(){
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
