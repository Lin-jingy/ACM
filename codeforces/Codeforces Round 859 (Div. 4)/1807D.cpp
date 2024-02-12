#include<bits/stdc++.h>

void solve(){
    int n, q;
    std::cin >> n >> q;
    std::vector<long long>a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], pre[i] = pre[i - 1] + a[i];
    while(q--){
        int flag = pre[n] % 2;
        int l, r, k;
        std::cin >> l >> r >> k;
        long long mid = (1LL * r - l + 1) * k - (pre[r] - pre[l - 1]);
        if(mid < 0) mid += (long long)1e18;
        if(mid % 2 == 1) flag = 1 - flag;
        std::cout << (flag ? "YES" : "NO") << std::endl;
    } 
}
signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--)solve();
    return 0;
}