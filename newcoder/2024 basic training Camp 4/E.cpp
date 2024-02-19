#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;
int a[N], pre[N], r[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("1.txt", "r", stdin);
    // clock_t start=clock();
    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans = 0;
    std::vector<std::pair<int, int>> v;
    std::map<int, std::vector<int>> mp;
    for(int i = 1; i <= n; ++i) {
        pre[i] = (pre[i - 1] + a[i]) % k;
        mp[pre[i]].push_back(i);
    }
    for(auto &i:mp) std::reverse(i.second.begin(), i.second.end());
    for(int i = 1; i <= n; ++i) {
        auto &it = mp[pre[i - 1] % k];
        while(!it.empty() and it.back() < i) it.pop_back();
        if(!it.empty()) r[it.back()] = i;
    }
    int la = 0;
    for(int i = 1; i <= n; ++i) {
        if(la >= r[i]) continue;
        la = i;
        ++ans;
    }
    
    std::cout << ans << '\n';

    // clock_t end=clock();
    // std::cout<<"Total time:"<<(double)(end-start)/CLOCKS_PER_SEC*1000<<"ms";

    return 0;
}