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

const int N = 1e4 + 5;
const int M = 1e2 + 5;
int n, m;
int a[N][M],tr[N * M];
#define lowbit(x) (x & (-x))
void updt(int x){
	while(x <= n*m){
		++tr[x];
		x += lowbit(x);
	}
}
int query(int x){
	int res = 0;
	while(x){
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}

void solve(){
	std::cin >> n >> m;
    std::vector<int>b(n * m);
	int cnt = m * (m + 1) / 2;
	for(int i(1); i <= n; ++i) for(int j(1); j <= m; ++j){
		std::cin >> a[i][j];
		b[(i - 1) * m + j] = a[i][j];
	}
	std::sort(ALL(b));
    int ans(0);
	for(int i(n); i >= 1; --i){
		if(i != n){
			int tmp = ans;
			ans += cnt * (n - i);
			for(int j(1); j <= m; ++j){
				ans += query(std::lower_bound(ALL(b), a[i][j]) - b.begin());
			}
		}
		for(int j(1); j <= m; ++j) updt(std::lower_bound(ALL(b), a[i][j]) - b.begin());
	}
	std::cout << ans << '\n';
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
