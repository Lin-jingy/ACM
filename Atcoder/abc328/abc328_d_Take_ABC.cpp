#include<bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<char> l;
    for(auto i:s) {
        l.push_back(i);
        if(l.size() >= 3) {
            if(l[l.size() - 1] == 'C' and l[l.size() - 2] == 'B' and l[l.size() - 3] == 'A') 
                l.pop_back(), l.pop_back(), l.pop_back();
        }
    }
    for(auto i:l) std::cout << i;


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