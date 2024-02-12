#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    // int ans = 0;
    // int a[n + 1];
    // for(int i = 1; i <= n; ++i) a[i] = i;
    
    // do{
    //     int k = 0, mx = 0;
    //     for(int i = 1; i <= n; ++i) k += a[i] * i, mx = std::max(mx, a[i] * i);
    //     //for(int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    //     k -= mx;
    //     //std::cout << "->" << k << '\n';
    //     ans = std::max(k, ans);
    // }while(std::next_permutation(a + 1, a + 1 + n));

    // for(int i = 1; i <= n; ++i) a[i] = i;
    
    // do{
    //     int k = 0, mx = 0;
    //     for(int i = 1; i <= n; ++i) k += a[i] * i, mx = std::max(mx, a[i] * i);
    //     k -= mx;
    //     if(k == ans){
    //         for(int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    //         std::cout << '\n';
    //         break;
    //     }
    // }while(std::next_permutation(a + 1, a + 1 + n));

    // std::cout << ans << '\n';

    int ans = 0;
    for(int i = 0; i <= n; ++i){
        int k = 0;
        int mx = 0;
        int flag = i + 1;
        for(int j = 1; j <= i; ++j) k += j * j, mx = std::max(mx, j * j);
        for(int j = n; j > i; --j) k += flag * j, mx = std::max(mx, j * flag++);
        ans = std::max(ans, k - mx);
    }

    std::cout << ans << '\n';
}


int main(){
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}