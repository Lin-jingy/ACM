#include<bits/stdc++.h>

#define int long long 

void solve(){
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int>a(m + 5), f(m + 5);
    for(int i = 1; i <= m; ++i) std::cin >> a[i];

    a[m + 1] = n + 1,f[m + 1] = 0;
	for(int i = m; i >= 1; --i) f[i] = f[i + 1] + (a[i + 1] - a[i] - 1) / d + 1;
	int mn = LONG_LONG_MAX, sum = 0; 
	int k = 0;
	if(a[1] != 1) a[0] = 1, k++;
	for(int i = 1; i <= m; ++i){
		int c1 = k + (a[i + 1] - a[i - 1] - 1) / d + f[i + 1];
		if(a[i] == 1) c1 = f[1];
		if(c1 < mn) mn = c1, sum = 1;
		else if(c1 == mn) sum++;
		k += (a[i] - a[i - 1] - 1) / d + 1;
	}
	std::cout << mn << ' '  << sum << '\n';

}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--) solve();
    return 0;
}
