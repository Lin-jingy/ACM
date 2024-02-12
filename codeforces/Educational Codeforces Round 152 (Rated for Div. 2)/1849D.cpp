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

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 2);
	for (size_t i(1); i <= n; i++){
		std::cin >> a[i];
		if (a[i] and a[i - 1]) a[i - 1] = std::max(a[i - 1], a[i]), i--, n--;
	}
    int ans(0);
	for (size_t i(1); i <= n; i++) if (a[i] == 2) a[i - 1] = a[i + 1] = -1, ans++;
	a[0] = -1;
	for (size_t i(1); i <= n; i++)
		if (a[i] == 1){
			if (!a[i - 1]) a[i - 1] = -1;
			else if (!a[i + 1]) a[i + 1] = -1;
			ans++;
		}
	for (size_t i(1); i <= n; i++) if (!a[i]) ans++;
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
