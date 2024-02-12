#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    int p;
    std::cin >> p;
    double ans = 0;
    for(int i = 0; i < 1000000; ++i) {
        std::random_shuffle(a.begin(), a.end()); 
        int sum = 0;
        for(auto j:a) {
            if(sum + j <= p) sum += j, ++ans;
            else break;
        }
    }
    ans /= 1000000;
    std::cout << ans << '\n';


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