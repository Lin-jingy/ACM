#include<bits/stdc++.h>

struct node {
    int w, s;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    node x;
    std::cin >> x.w >> x.s;
    for(int i = 0; i < n - 1; ++i) std::cin >> a[i].w >> a[i].s;
    for(auto i:a) {
        if(i.s >= x.s and i.w >= x.w) {
            std::cout << -1 << '\n';
            return ;
        }
    }
    std::cout << x.w << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}