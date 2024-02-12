#include<bits/stdc++.h>

#define int long long 

signed main(){
    int n, m;
    std::cin >> n >> m;
    int ans = 0;
    n -= m;
    while(n > 0){
        if(m == 1)break;
        if((m + 1) / 2 <= n) n -= (m+1)/2, ++ans, m = (m + 1) / 2;
        else break;
    }
    ans += n;
    std::cout << ans << '\n';
    return 0;
}