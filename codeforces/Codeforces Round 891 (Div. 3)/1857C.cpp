#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    int len = n * (n - 1) / 2;
    std::vector<int>a(len);
    for(int i = 0; i < len; ++i) std::cin >> a[i];
    std::vector<int>ans;
    std::sort(a.begin(), a.end(), std::greater<>());
    int size = n - 1;
    while(!a.empty()){
        int k = size;
        ans.emplace_back(a.back());
        while(k--)a.pop_back();
        --size;
    }
    ans.emplace_back(1e9);
    for(auto i:ans) std::cout << i << ' ';
    std::cout << '\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}