#include<bits/stdc++.h>

#define int long long
std::array<int, 26> a = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

void solve() {
    int n, p;
    std::cin >> n >> p;
    if(n <= p) {
        std::cout << n << '\n';
        return ;
    }
    int flag = std::upper_bound(a.begin(), a.end(), p) - a.begin() - 1;
    std::random_shuffle(a.begin(), a.begin() + flag + 1);
    std::vector<int> p1, p2;
    p1.emplace_back(1);
    p2.emplace_back(1);
    for(int i = 0; i <= flag; ++i) {
        if(p1.size() < p2.size()) {
            int len = p1.size();
            for(int j = 0; j < len; ++j) {
                int sum = p1[j];
                while(1) {
                    sum *= a[i];
                    if(sum > n) break;
                    p1.emplace_back(sum);
                }
            }
        }else {
            int len = p2.size();
            for(int j = 0; j < len; ++j) {
                int sum = p2[j];
                while(1) {
                    sum *= a[i];
                    if(sum > n) break;
                    p2.emplace_back(sum);
                }
            }
        }
    }
    std::sort(p2.begin(), p2.end());
    int ans = 0;
    for(auto i:p1) {
        ans += std::upper_bound(p2.begin(), p2.end(), n / i) - p2.begin();
    }
    std::cout << ans << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}