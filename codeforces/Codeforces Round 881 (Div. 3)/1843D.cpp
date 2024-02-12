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

const int N = 2e5 + 5;
std::vector<int>v[N];

int dfs(int pos, std::vector<int> &p, std::vector<bool> &vis){
    int k = 0;
    vis[pos] = 1;
    for(auto i:v[pos]){
        if(!vis[i]) k += dfs(i, p, vis);
    }
    p[pos] = k;
    if(k == 0) p[pos] = 1;
    return p[pos];
}

void solve(){
    int n; 
    std::cin >> n;
    std::vector<int>mid;
    for(int i(1); i <= n; ++i) v[i] = mid;
    for(int i(0), x, y; i < n - 1; ++i) {
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    std::vector<int>p(n + 1);
    std::vector<bool>vis(n + 1);
    dfs(1, p, vis);
    int q;
    std::cin >> q;
    while(q--){
        int x, y;
        std::cin >> x >> y;
        std::cout << p[x] * p[y] << '\n';
    }

    
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
