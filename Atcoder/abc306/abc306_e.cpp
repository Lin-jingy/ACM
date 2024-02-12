// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

void solve(){
    int n, k, q;
    std::cin >> n >> k >> q;
    std::multiset<int>s1;
    std::multiset<int>s2;
    std::vector<int>a(n + 1);
    int ans(0);
    for(int i = 1; i <= k; ++i) s1.insert(0);
    for(int i = k + 1; i <= n; ++i) s2.insert(0);
    while(q--){
        int pos, y;
        std::cin >> pos >> y;
        auto it = s1.find(a[pos]);
        if(it != s1.end()) s1.erase(it), ans -= a[pos];
		else s2.erase(s2.find(a[pos]));
		a[pos] = y;
		if(!s2.empty() and y >= *s2.rbegin()) s1.insert(y), ans += y;
		else s2.insert(y);
		if(s1.size() < k){
			s1.insert(*s2.rbegin());
			ans += *s2.rbegin();
			s2.erase(s2.find(*s2.rbegin()));
		}
		if(s1.size() > k){
			s2.insert(*s1.begin());
			ans -= *s1.begin();
			s1.erase(s1.begin());
		}
        std::cout << ans << '\n';
    }
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
