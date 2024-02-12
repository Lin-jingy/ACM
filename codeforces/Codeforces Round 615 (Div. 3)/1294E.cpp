#include<bits/stdc++.h>

#define int long long

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) std::cin >> a[i][j];
	std::vector<int> sum(n + 1), p(n + 1);
	
	int ans = 0;
	
	for(int j = 1; j <= m; ++j) {
		for(int i = 0; i <= n; ++i) sum[i] = 0, p[i] = 0;
		int mx = (n - 1) * m + j;
		for(int i = 1; i <= n; ++i) {
			if(a[i][j] > mx) {
				p[i] = 1e7;
				continue;
			}
			if((a[i][j] - j) % m == 0) {
				int k = (i - 1) * m + j;
				p[i] = abs(a[i][j] - k) / m;
				if(a[i][j] > k) p[i] = n - p[i];
			}else p[i] = 1e7;
		}
		int mid = n;
		for(int i = 1; i <= n; ++i) {
			if(p[i] <= n) sum[p[i]]++;
		}
		for(int i = 0; i <= n; ++i) {
			//std::cout << i << ' ' << sum[i] << '\n'; 
			mid = std::min(mid, n + i - sum[i]);
		}
		//std::cout << "           " << mid << '\n';
		ans += mid;
	}
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	//std::cin >> T; 
	while(T--) solve();
	return 0;
}