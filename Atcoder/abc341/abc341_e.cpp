#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = ' ' + s;

    std::set<int> set;
    for(int i = 2; i <= n; ++i) 
        if(s[i] == s[i - 1]) set.insert(i);

    while(q--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if(op == 1) {
            if(l != 1) {
                if(set.count(l)) set.erase(l);
                else set.insert(l);
            }
            if(r != n) {
                if(set.count(r + 1)) set.erase(r + 1);
                else set.insert(r + 1);
            }
        }else {
            auto it = set.lower_bound(l + 1);
            if(it != set.end() and *it <= r) std::cout << "No\n";
            else std::cout << "Yes\n";
        } 
    }
    return 0;
}