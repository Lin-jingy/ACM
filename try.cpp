#include <bits/stdc++.h>

template <class T>
using vec = std::vector<T>;

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	vec<vec<int>> v(n, vec<int>(m));
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) std::cin >> v[i][j];
	std::map<vec<int>, int> mp;
	for(int i = 0; i < n; ++i) mp[v[i]]++;
	std::cout << mp.size() << '\n';
	std::vector<std::pair<int, vec<int>>> P;
	for(auto i:mp) P.push_back({i.second, i.first});
	std::sort(P.begin(), P.end(), [](auto &a, auto &b) {
		if(a.first != b.first) return a.first > b.first;
		else return a.second < b.second;
	});
	for(int i = 0; i < P.size(); ++i) {
		std::cout << P[i].first << ' ';
		
	}
	return 0;
}