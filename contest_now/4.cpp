#include <bits/stdc++.h>

#define int long long 

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = ' ' + s;
    
    int l = std::count(s.begin(), s.end(), '(');
    int r = n - l;

    int ans = 0;
    if(l > r) {
        std::vector<int> pre(n + 1);
        std::multiset<int> mp;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == '(') ++pre[i];
            else --pre[i];
            pre[i] += pre[i - 1];
            mp.insert(pre[i]);
        }

        for(int i = 1; i <= n; ++i) {
            if(s[i] == '(' and *mp.begin() >= 2) ++ans;
            if(pre[i] < 0) break;
            mp.erase(mp.find(pre[i]));
        }
    } else if(l < r) {
        std::vector<int> pre(n + 1);
        std::multiset<int> mp;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == ')') ++pre[i];
            else --pre[i];
            pre[i] += pre[i - 1];
            mp.insert(pre[i]);
        }

        for(int i = 1; i <= n; ++i) {
            if(s[i] == ')' and *mp.rbegin() <= 2) ++ans;
            if(pre[i] > 0) break;
            mp.erase(mp.find(pre[i]));
        }
    }

    std::cout << ans << '\n';
    return 0;
}