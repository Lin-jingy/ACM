// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<int>p1(n), p0(n);
    if(s[0] == '0') p0[0] = 0;
    else p0[0] = -1;
    for(size_t i(1); i < n; ++i){
        if(s[i] == '0') p0[i] = i;
        else p0[i] = p0[i - 1];
    }
    if(s[n - 1] == '1') p1[n - 1] = n - 1;
    else p1[n - 1] = n;
    for(int i(n - 2); i >= 0; --i){
        if(s[i] == '1') p1[i] = i;
        else p1[i] = p1[i + 1];
    }
    std::map<PII, int>mp;
    while(m--){
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        int ll = p1[l];
        int rr = p0[r];
        if(ll > rr) mp[{-1, -1}]++;
        else mp[{ll, rr}]++;
        
    }
    std::cout << mp.size() << '\n';

}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
