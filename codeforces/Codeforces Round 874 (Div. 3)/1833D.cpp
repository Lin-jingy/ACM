#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    int mx = n;
    if(a[0] == n) --mx;
    int flag = find(a.begin(), a.end(), mx) - a.begin();
    if(flag == n - 1) flag = n;
    std::vector<int>ans;
    for(int i = 0; i < flag; ++i){
        std::vector<int>mid;
        for(int j = flag; j < n; ++j) mid.emplace_back(a[j]);
        for(int j = flag - 1; j >= i; --j) mid.emplace_back(a[j]);
        for(int j = 0; j < i; ++j) mid.emplace_back(a[j]);
        if(ans.empty()) ans = mid;
        else{
            for(int j = 0 ; j < n; ++j){
                if(ans[j] > mid[j]) break;
                else if(ans[j] < mid[j]) {
                    ans = mid;
                    break;
                }
            }
        }
    }
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}