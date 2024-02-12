#include<bits/stdc++.h>

std::array<int, 4> pos = {0, 2, 3, 4};
std::set<int> s[4];

void move(int a, int b) {
    pos[a] += b;
    std::vector<int> mid;
    for(auto i:s[a]) mid.push_back(i);
    for(int i = 1; i <= 3; ++i) {
        if(s[i].count(a)) {
            s[i].erase(a);
            for(auto j:mid) if(s[i].count(j)) s[i].erase(j);
        }
    }
    for(int i = 1; i <= 3; ++i) {
        if(a == i) continue;
        if(pos[i] == pos[a]) {
            s[i].insert(a);
            for(auto j:s[a]) s[i].insert(j);
        }
    }
    for(auto i:mid) pos[i] += b;
}

void solve() {
    pos = {0, 2, 3, 4};
    for(int i = 1; i <= 3; ++i) s[i].clear();
    for(int i = 1; i <= 12; ++i) {
        int a, b;
        std::cin >> a >> b;
        move(a, b);
    }
    for(int i = 1; i <= 3; ++i) if(pos[i] != 9) {
        std::cout << "N\n";
        return ;
    }
    std::cout << "Y\n";
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}