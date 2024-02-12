#include<bits/stdc++.h>

int main(){
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;

        int ans(0);
        int x, y;
        for(int i(0); i < n; ++i) {
            std::cin >> x >> y;
            if(x - y > 0) ++ans;
        }

        std::cout << ans << '\n';

    }

}