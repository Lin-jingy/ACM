#include <bits/stdc++.h>

struct node {
    int k, id;
    friend bool operator<(const node &a, const node &b) {
        if(a.k != b.k) return a.k > b.k;
        else return a.id < b.id;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    std::set<node> s;
    for(int i = 0, x; i < m; i++) {
        std::cin >> x;
        if(a[x] != 0) s.erase({a[x], x});
        ++a[x];
        s.insert({a[x], x});
        std::cout << s.begin()->id << '\n';
    }


}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}
