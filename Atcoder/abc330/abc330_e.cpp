#include <bits/stdc++.h>

const int N = 2e5;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    std::map<int, int> mp;
    std::set<int> s;
    for(int i = 1; i <= n; ++i) std::cin >> a[i], mp[a[i]]++;
    for(int i = 0; i <= 2e5; ++i) s.insert(i);
    for(auto [i, _]:mp) if(i <= N and s.count(i)) s.erase(i); 
    while(q--) {
        int i, x;
        std::cin >> i >> x;
        mp[a[i]]--;
        if(mp[a[i]] == 0) {
            mp.erase(a[i]);
            s.insert(a[i]);
        }
        mp[x]++;
        a[i] = x;
        if(mp[x] == 1 and x <= N) {
            s.erase(x);
        }
        std::cout << *s.begin() << '\n';
    }

    return 0;
}
