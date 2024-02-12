#include<bits/stdc++.h>

void solve(){
    int n, ans = 0, sum = 0;
    std::cin >> n;
    for(int i = 1, x; i <= n; ++i){
        std::cin >> x;
        if(x == 0) ++sum, ans = std::max(ans, sum);
        else sum = 0;
    }
    std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int T = 1;
	std::cin >> T;
	while (T--)solve();
	return 0;
}