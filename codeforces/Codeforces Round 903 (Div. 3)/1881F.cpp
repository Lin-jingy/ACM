#include<bits/stdc++.h>

const int N = 2e5 + 5;
std::vector<std::vector<int>> a(N);
int dep[N];
std::bitset<N> p;
std::bitset<N> vis;

void dfs1(int pos, int d) {
	if(vis[pos]) return ;
	vis[pos] = true;
	dep[pos] = d;
	for(auto i:a[pos]) dfs1(i, d + 1);
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	p.reset(), vis.reset();
	memset(dep, 0, sizeof(int) * (n + 1));
	for(int i = 0; i <= n + 1; ++i) a[i].clear();
	for(int i = 1, x; i <= k; ++i) std::cin >> x, p[x] = true;
	for(int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		a[u].emplace_back(v);
		a[v].emplace_back(u);
	}
	if(k == 1) {
		std::cout << 0 << '\n';
		return ;
	}
	dfs1(1, 0);
	
	int pos = 1;
	for(int i = 1; i <= n; ++i) if(p[i] and dep[i] > dep[pos]) pos = i;
	//for(int i = 1; i <= n; ++i) std::cout << dep[i] << ' ';
	//std::cout << '\n';
	vis.reset();
	dfs1(pos, 0);
	int mx = 0;
	for(int i = 1; i <= n; ++i) if(p[i] and dep[i] > dep[mx]) mx = i;
	int dis = dep[mx];
	std::cout << (dis + 1) / 2 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while(T--) solve();
	return 0;
}