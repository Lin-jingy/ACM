#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1);
    long long v = 1;
    bool flag = false;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= n; ++i){
        if(v * a[i] >= (int)1e9){
            flag = true;
            break;
        }else v *= a[i];
    }
    if(flag){
        int l, r;
        for(int i = 1; i <= n; ++i) if(a[i] != 1){
            l = i;
            break;
        }
        for(int i = n; i >= 1; --i) if(a[i] != 1){
            r = i;
            break;
        }
        std::cout << l << ' ' << r << '\n';
    }else{
        std::vector<long long>pre(n + 1, 1), sum(n + 1);
        std::vector<int>p;
        for(int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] * a[i];
            sum[i] = sum[i - 1] + a[i];
            if(a[i] != 1) p.emplace_back(i);
        }
        std::pair<int, int>ans = {-1, -1};
        long long mx = 0;
        for(int i = 0; i < p.size(); ++i){
            for(int j = i; j < p.size(); ++j){
                long long k = pre[p[j]] / pre[p[i] - 1] + sum[p[i] - 1] + sum[n] - sum[p[j]];
                if(k > mx) mx = k, ans = {p[i], p[j]};
            }
        }
        if(ans.first != -1)std::cout << ans.first << ' ' << ans.second << '\n';
        else std::cout << 1 << ' ' << 1 << '\n';
    }   


}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}