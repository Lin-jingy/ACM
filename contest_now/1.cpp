#include <bits/stdc++.h>

#define int long long 

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = '1' + s;
    
    std::vector<char> ans;
    bool op = 1;
    char pos1 = 'C', pos2 = 'B';
    // if(s[1] == '1') pos2 = 'B';
    // else pos1 = 'C', pos2 = 'B';

    for(int i = 1; i <= n; ++i) {
        if(s[i] == s[i - 1]) {
            ans.push_back(pos1);
        } else {
            std::set<char> op;
            op.insert('A');
            op.insert('B');
            op.insert('C');
            op.erase(pos1);
            op.erase(pos2);
            ans.push_back(*op.begin());
            pos2 = pos1;
            pos1 = *op.begin();
        }
    }
    
    std::reverse(ans.begin(), ans.end());
    for(auto i:ans) std::cout << i;
    return 0;
}