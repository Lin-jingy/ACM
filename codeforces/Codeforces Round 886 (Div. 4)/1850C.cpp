// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    std::string a[8];
    for(size_t i(0); i < 8; ++i) std::cin >> a[i];
    std::string ans;
    for(size_t i(0); i < 8; ++i){
        for(size_t j(0); j < 8; ++j){
            if(a[i][j] != '.'){
                for(size_t k(i); k < 8; ++k){
                    if(a[k][j] != '.') ans += a[k][j];
                    else break;
                }
                goto A;
            }
        }
    }
    A:;
    std::cout << ans << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
