#include<bits/stdc++.h>

std::bitset<2000005> bit;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    // std::list<char> ls;
    // for(auto i:s) ls.push_back(i);
    // if(s.back() == 'R') {
    //     for(auto it = ls.begin(); it != --ls.end() && it != ls.end(); ) {
    //         if(*(it) == 'R') {
    //             if(*(++it) == 'L') {
    //                 it = ls.erase(--it);
    //                 it = ls.erase(it);
    //                 if(it != ls.begin()) --it;
    //             }
    //         }else ++it;
    //     }
    //     for(auto i:ls) if(i == 'R') goto A;
    //     std::cout << 0 << '\n';
    // }else {
    //     for(auto it = ls.begin(); it != --ls.end() && it != ls.end(); ) {
    //         if(*(it) == 'L') {
    //             if(*(++it) == 'R') {
    //                 it = ls.erase(--it);
    //                 it = ls.erase(it);
    //                 if(it != ls.begin()) --it;
    //             }
    //         }else ++it;
    //     }
    //     for(auto i:ls) if(i == 'L') goto A;
    //     std::cout << 0 << '\n';
    // }
    // A:;
    auto check = [&](int mid) -> bool {
        int pos = 0;
        bit.reset();
        bit[1e6] = 1;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == 'L' and pos - 1 != mid) --pos;
            else if(s[i] == 'R' and pos + 1 != mid) ++pos;
            bit[pos + 1e6] = 1;
        }
        if(s.back() == 'L') {
            if(!bit[pos - 1 + 1e6]) return true;
            else return false;
        }else {
            if(!bit[pos + 1 + 1e6]) return true;
            else return false;
        }
    };
    if(check(1e6 + 1)) {
        std::cout << 1 << '\n';
        return ;
    }
    if(s.back() == 'R') {
        int l = -1e6, r = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
    }else {
        int l = 1, r = 1e6;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
    }
    if(ans == 0) std::cout << ans << '\n';
    else std::cout << std::max(1, abs(ans)) << '\n';
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