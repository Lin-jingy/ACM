#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::multiset<int> s, s2;
    std::vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> a[i], s.insert(a[i]), b[i] = a[i];
    std::sort(b.begin() + 1, b.end());
    for(int i = 2; i <= n; i++) s2.insert(b[i] - b[i - 1]);
    int q;
    std::cin >> q;
    while(q--){
        int x, y;
        std::cin >> x >> y;
        if(n==1){
            std::cout << y << '\n';
            continue;
        }
        if(a[x] == *s.begin()){
            auto r = ++s.begin();
            s2.erase(s2.find(*r - a[x]));
            s.erase(s.find(a[x]));
        }else if(a[x] == *s.rbegin()){
            auto l = --prev(s.end());
            s2.erase(s2.find(a[x] - *l));
            s.erase(s.find(a[x]));  
        }else{
            auto r = s.lower_bound(a[x]);
            auto l = r;
            ++r, --l;
            s2.erase(s2.find(*r - a[x]));
            s2.erase(s2.find(a[x] - *l));
            s2.insert(*r - *l);
            s.erase(s.find(a[x]));
        }
        if(y <= *s.begin()){
            s2.insert(*s.begin() - y);
            s.insert(y);
        }else if(y >= *s.rbegin()){
            s2.insert(y - *s.rbegin());
            s.insert(y);
        }else{
            auto r = s.lower_bound(y);
            auto l = r;
            --l;
            s2.insert(*r - y);
            s2.insert(y - *l);
            s2.erase(s2.find(*r - *l));
            s.insert(y);
        }
        std::cout << *s.rbegin() + *s2.rbegin() << ' ';
        a[x] = y;
    }
    std::cout << '\n'; 
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}