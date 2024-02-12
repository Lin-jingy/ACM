#include<bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for(int i = 0, x; i < n; ++i) std::cin >> x, mp[x]++;
    int q;
    std::cin >> q;
    while(q--) {
        long long x,y;
		std::cin >> x >> y;
		long long num = x * x - 4 * y;
        int sq = sqrt(num);
		if(num < 0 or 1ll * sq * sq != num){
			std::cout << 0 << ' ';
			continue;
		}
		if(num == 0){
			std::cout << 1ll * mp[(x - sq) / 2] * (mp[(x - sq) / 2] - 1) / 2 << ' ';
			continue;
		}
		long long n1 = x - sq, n2 = x + sq;
		std::cout << 1ll * mp[n1 / 2] * mp[n2 / 2]<< ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}