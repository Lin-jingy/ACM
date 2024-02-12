// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"

const int N = 2e5 + 5;
std::vector<PII> e[N]; 
bool flag; 
int dis[N];

void dfs(int u, int now) {
	if(dis[u]) return ; 
    dis[u] = now;
	for(auto it: e[u]) {
		if(flag) return ;
		int v = it.first, w = it.second;
		if(!dis[v]) dfs(v, dis[u] + w);
		else {
			if(dis[v] != dis[u] + w) {
				no;
				flag = 1;
				return ;
			}
		}
		if(flag) return ;
	}
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    for(size_t i(1); i <= n; i++) dis[i] = 0, e[i].clear();
    while(m--) {
    	int a, b, d; 
        std::cin >> a >> b >> d;
    	e[a].push_back({b, d});
    	e[b].push_back({a, -d});
	}
	flag = 0;
	for(size_t i(0); i <= n; i++) {
		if(!dis[i]) dfs(i, 1e15);
		if(flag) break;
	}
	if(!flag) yes;
}

signed main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while(_--) solve();
	return 0;
}