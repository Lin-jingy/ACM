#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1);
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	int ans = INT_MAX, k1 = 0,k2 = 0;
	for(int i = 1; i < n; i++) if(a[i] >= a[i+1]) k1++;
	ans = std::min(ans, k1);
	for(int i = 1;i < n; i++){
		if(a[i] >= a[i-1])k2++;
		if(a[i] >= a[i+1])k1--;
		ans = std::min(ans, k1 + k2);
	}
	std::cout << ans << "\n";
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}