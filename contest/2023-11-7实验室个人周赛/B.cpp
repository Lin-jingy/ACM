#include<bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
	char op = s.back();
    std::list<char> ls;
    for(auto i:s) ls.push_back(i);
    int mn = 0;
    int mx = 0;
    int pos = 0;
    bool L = false, R = false;
    for(auto i:s) {
        if(i == 'L') pos--;
        else pos++;
        mn = std::min(mn, pos);
        mx = std::max(mx, pos);
    }
    pos = 0;
    for(auto i:s) {
        if(i == 'L') pos--;
        else pos++;
        if(pos == mn) L = true;
        else if(pos == mx) R = true;
    }
    if(op == 'R') {
        for(auto it = ls.begin(); it != --ls.end() && it != ls.end(); ) {
            if(*(it) == 'R') {
                if(*(++it) == 'L') {
                    it = ls.erase(--it);
                    it = ls.erase(it);
                    if(it != ls.begin()) --it;
                }
            }else ++it;
        }
        int sumL = 0;
        for(auto i:ls) if(i == 'L') ++sumL;
        int sumR = ls.size() - sumL;
        if(sumL < sumR) {
            if(sumR < mx) std::cout << 0 << '\n';
            else if(sumR == mx and !R) std::cout << 1 << '\n';
            else std::cout << 1 << '\n';
        }else if(sumL == sumR) {
            std::cout << abs(mn) << '\n';
        }else std::cout << sumL - sumR << '\n';
        return ;
    }else {
        for(auto it = ls.begin(); it != --ls.end() && it != ls.end(); ) {
            if(*(it) == 'L') {
                if(*(++it) == 'R') {
                    it = ls.erase(--it);
                    it = ls.erase(it);
                    if(it != ls.begin()) --it;
                }
            }else ++it;
        }
        int sumR = 0;
        for(auto i:ls) if(i == 'R') ++sumR;
        int sumL = ls.size() - sumR;
        if(sumR < sumL) {
            if(sumL > mn) std::cout << 0 << '\n';
            else if(sumL == mn and !L) std::cout << 1 << '\n';
            else std::cout << 1 << '\n';
        }else if(sumL == sumR) {
            std::cout << mx << '\n';
        }else std::cout << sumR - sumL << '\n';
        return ;
    }
    

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