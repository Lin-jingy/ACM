#if __GNUC__
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
#else
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define and &&
#define or ||
#endif

#if _WIN64 && __GNUC__
#define dbg(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)

void err() {
    std::cout << std::endl
              << std::endl;
}

template <class T, class... Ts>
void err(T arg, Ts... args) {
    std::cout << std::fixed << std::setprecision(10) << arg << ' ';
    err(args...);
}
#else
#define dbg(...)
#endif
#if _WIN64 && __GNUC__
using int128 = __int128;
#endif
#define int long long
using PII = std::pair<int, int>;
#define All(x) x.begin(), x.end()
#define eb(x) emplace_back(x)
using vec = std::vector<int>;

void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<PII>> v(n + 1);
    std::vector<PII> a(n + 1);
    int begin, end;
    std::cin >> begin >> end;
    while(m--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        v[a].eb(PII(b, c));
        v[b].eb(PII(a, c));
    }
    for(int i = 1; i <= n; ++i) std::cin >> a[i].first >> a[i].second;
    std::vector<vec> d(n + 1);

    auto dij = [&](int begin) -> void{
        std::vector<int> dis(n + 1, LONG_LONG_MAX);
        std::vector<bool> st(n + 1);
        dis[begin] = 0;
        std::priority_queue<PII,std::vector<PII>,std::greater<PII>>q;
        q.push({0,begin});
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int ds = it.first, pos = it.second;
            if(st[pos])continue;
            st[pos] = true;
            for(auto i : v[pos]){
                int p = i.first;
                int k = i.second;
                if(ds + k < dis[p]){
                    dis[p] = ds + k;
                    q.push({dis[p], p});
                }
            }
        }
        d[begin] = dis;
    };

    for(int i = 1; i <= n; ++i) dij(i);
    for(int i = 1; i <= n; ++i) v[i].clear();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(d[i][j] <= a[i].first and i != j) v[i].eb(PII(j, a[i].second));
            if(d[j][i] <= a[j].first and i != j) v[j].eb(PII(i, a[j].second));
        }
    }
    dij(begin);
    if(d[begin][end] > 1e12) std::cout << -1 << '\n';
    else std::cout << d[begin][end] << '\n';

}