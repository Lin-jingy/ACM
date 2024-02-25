#include <bits/stdc++.h>

#define int long long

void solve() {
    int n, s, k;
    std::cin >> n >> s >> k;
    std::vector<int> ans;
    int la;
    if(k == 0) {
        for(int i = 1; i <= n; ++i) ans.push_back(1);
        ans.front() += s - n;
        goto TEST;
    }
    if(n < 2 * k + 1) {
        std::cout << "-1\n";
        return ;
    }
    if(2 * k + 1 == n) {
        // int la = s - (3 * k + 2);
        // if(la == 0 or (la > 0 and la >= k + 1)) {
        //     int h = (s - k) / (k + 1);
        //     int last = s - h * (k + 1);
        //     int L1 = last / k;
        //     int num = last % k;
        //     if(num != 0 and L1 + 1 >= h) {
        //         std::cout << "-1\n";
        //         return ;
        //     }
        //     ans.push_back(h);
        //     for(int i = 1; i <= num; ++i) ans.push_back(L1 + 1), ans.push_back(h);
        //     for(int i = num + 1; i <= k; ++i) ans.push_back(L1), ans.push_back(h);
        //     std::cout << '\n';
        //     goto TEST;
        // } else {
        //     std::cout << "-1\n";
        //     return ;
        // }
        ans.push_back(2);
        s -= 2;
        for(int i = 1; i <= k; ++i) ans.push_back(1), ans.push_back(2), s -= 3;
        while(ans.size() < n) ans.push_back(1), --s;
        if(s < 0) {
            std::cout << "-1\n";
            return ;
        }
        for(int i = 0; i < n; i += 2) ans[i] += s / (k + 1);
        s %= k + 1;
        for(int i = 1; i < n; i += 2) ans[i] += s / k;
        s %= k;
        for(int i = 1; i < n; i += 2) {
            if(s != 0) ans[i]++, s--;
        }
        for(int i = 1; i < n; i += 2) {
            if(ans[i] >= ans[i - 1]) {
                std::cout << "-1\n";
                return ;
            }
        } 
        for(int i = 0; i < n; ++i) std::cout << ans[i] << ' ';
        std::cout << '\n';
        return ;
    }
    // ans.push_back(2);
    // for(int i = 1; i <= k; ++i) ans.push_back(1), ans.push_back(2);
    // la = n - ans.size();
    // s -= 3 * k + 2;
    // if(s < la or n < 2 * k + 1) {
    //     std::cout << "-1\n";
    //     return ;
    // }
    // for(int i = 1; i < la; ++i) ans.push_back(1), s--;
    // ans.push_back(s);
    ans.push_back(2);
    s -= 2;
    for(int i = 1; i <= k; ++i) ans.push_back(1), ans.push_back(2), s -= 3;
    while(ans.size() < n) ans.push_back(1), --s;
    if(s < 0) {
        std::cout << "-1\n";
        return ;
    }
    ans[(k + 1) * 2 - 1] += s;
    TEST:;
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';
    int kk = 0;
    for(int i = 1; i < ans.size() - 1; ++i) {
        if(ans[i - 1] == ans[i + 1] and ans[i] < ans[i - 1]) ++kk;
    }
    assert(kk == k && ans.size() == n);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}