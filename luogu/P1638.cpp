#include<bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int l = 1, r = m;
    std::unordered_map<int, int> mp;
    for(int i = l; i <= r; ++i) mp[a[i]]++;
    int mn = INT_MAX, ans = 0;
    while(r < n) {
        while(mp.size() < m and r < n) mp[a[++r]]++;
        if(mp.size() == m and r - l + 1 < mn) mn = r - l + 1, ans = l;
        while(mp.size() == m and l <= r) {
            mp[a[l]]--;
            if(mp[a[l++]] == 0) mp.erase(a[l - 1]);
            if(mp.size() == m and r - l + 1 < mn) mn = r - l + 1, ans = l;
        }
    }
    std::cout << ans << ' ' << ans + mn - 1 << '\n';

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