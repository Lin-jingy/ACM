#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], pre[i] = std::max(a[i], pre[i - 1]);
    int flag = n;
    for(; flag >= 1; --flag) if(pre[flag] != a[flag]) break;

    std::cout << pre[flag] << '\n';


}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}