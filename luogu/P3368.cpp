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
#define lowbit(x) (x & (-x))

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<int>f(n + 1);
    auto add = [&](int pos, int k){
        for(; pos <= n; pos += lowbit(pos)) f[pos] += k;
    };
    auto addmore = [&](int l, int r, int k){
        add(l, k);
        add(r + 1, -k);
    };
    auto pre = [&](int x){
        int sum = 0;
        for(; x > 0; x -= lowbit(x)) sum += f[x];
        return sum;
    };
    auto ask = [&](int x){
        return pre(x) + a[x];
    };
    while(m--){
        int op;
        std::cin >> op;
        if(op == 1){
            int x, y, k;
            std::cin >> x >> y >> k;
            addmore(x, y, k);
        }else{
            int x;
            std::cin >> x;
            std::cout << ask(x) << '\n';
        }
    }
    return 0;
}
