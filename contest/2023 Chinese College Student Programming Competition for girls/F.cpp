#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), p(n + 1), pre(n + 1);
    int flag = false;
    int mx = 1;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i], p[a[i]]++;
        if(a[i] > i or a[i] > mx) flag = 1;
        mx = std::max(a[i] + 1, mx);
    }
    if(flag) {
        std::cout << "-1\n";
        return ;
    }
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + p[i];
    std::vector<int> ans;
    std::vector<bool> vis(n + 1);
    for(int i = 1; i <= n; ++i) {
        if(vis[pre[a[i]]]) {
            std::cout << "-1\n";
            return ;
        }
        vis[pre[a[i]]] = 1;
        ans.push_back(pre[a[i]]--);
    }
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}