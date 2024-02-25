#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s, op;
    std::cin >> s >> op;
    s.erase(s.begin()); 
    s.erase(s.begin()); 
    int n = stoi(s);
    int k = n / 2 + 1;
    int k1 = 0, k2 = 0;
    for(int i = 0; i < op.size(); ++i) {
        if(op[i] == 'R') k1++;
        else k2++;
        if(k1 == k) {
            std::cout << "kou!\n" << i + 1 << '\n';
            return 0;
        }
        if(k2 == k) {
            std::cout << "yukari!\n" << i + 1 << '\n';
            return 0;
        }
    }
    std::cout << "to be continued.\n" << op.size() << '\n';
    return 0;
}