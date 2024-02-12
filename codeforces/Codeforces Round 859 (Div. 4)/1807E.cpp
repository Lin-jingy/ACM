#include<bits/stdc++.h>

#define int long long 

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;

    auto check = [&](int mid){
        std::cout << '?' << ' ' << mid - l + 1 << ' ';
        for(int i = l; i <= mid; ++i) std::cout << i << ' ';
        std::cout << std::endl;
        int sum;
        std::cin >> sum;
        if(sum == pre[mid] - pre[l - 1])l = mid + 1;
        else r = mid;
    };

    while(l <= r){
        if(l == r){
            std::cout << '!' << ' ' << l << std::endl;
            return ;
        }
        int mid = (l + r) >> 1; 
        check(mid);
    }
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}