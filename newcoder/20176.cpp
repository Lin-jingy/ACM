// #pragma GCC optimize(3)
#include<iostream>
#include<unordered_map>

#define int long long
int n, k;

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    std::unordered_map<int, int>mp;
    while(std::cin >> n >> k){
        int ans = 0;
        for(int i(0), x; i < n; ++i) {
            std::cin >> x;
            for(int j = 1; j * j <= x; ++j){
                if(x % j == 0){
                    mp[j]++;
                    if(j != x / j) mp[x/j]++;
                } 
                
            }
        }
        for(auto i:mp) if(i.second >= k)ans = std::max(ans, i.first);
        std::cout << ans << '\n';
    }
    return 0;
}
