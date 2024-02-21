#include <bits/stdc++.h>

#define int long long
int a[100005];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    int ans1 = 0;
	int ans2 = a[1] - 1;
	int d = a[1] - 1;
	for(int i = 2; i <= n; i++){
		ans1 += std::min(a[i] - 1, d);
		d = a[i] - 1 - std::min(a[i] - 1, d);
	}
	ans1 += d;
	d = 0;
	for(int i = 2;i <= n; i++){
		ans2 += std::min(a[i] - 1, d);
		d = a[i] - 1 - std::min(a[i] - 1, d);
	}
	ans2 += d;
	std::cout << std::max(ans1,ans2);

    return 0;
}