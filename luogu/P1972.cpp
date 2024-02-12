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
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

class node{
public:
    int l, r;
    int k;
};

void solve(){
    int n;
    std::cin >> n;
    int si = sqrt(n);
    std::vector<int>a(n + 1);
    std::vector<int>pos(n + 1);
    for(int i(1); i <= n; ++i) {
        std::cin >> a[i];
        pos[i] = (i - 1) / si + 1;
    }
    int q;
    std::cin >> q;
    std::vector<node>v(q);
    for(int i(0); i < q; ++i) std::cin >> v[i].l >> v[i].r, v[i].k = i;
    sort(ALL(v), [&](node a, node b){
        if(pos[a.l] != pos[b.l]) return pos[a.l] < pos[b.l];
        if(pos[a.l] % 2 == 1) return a.r > b.r;
        else return a.r < b.r;
    });
    int L = 1, R = 0;
    std::unordered_map<int, int>mp;
    auto add = [&](int x){mp[a[x]]++;};
    auto del = [&](int x){
        mp[a[x]]--;
        if(mp[a[x]] == 0) mp.erase(a[x]);
    };
    std::vector<int>ans(q);
    for(int i = 0; i < q; ++i){
        while(L < v[i].l) del(L++);
        while(R > v[i].r)  del(R--);
		while(L > v[i].l)  add(--L);
        while(R < v[i].r)  add(++R); 
        ans[v[i].k] = mp.size();
    }
    for(int i(0); i < q; ++i) std::cout << ans[i] << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
