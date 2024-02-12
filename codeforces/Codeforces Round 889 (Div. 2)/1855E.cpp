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

const int mod = 1e9 + 7;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}
#define rmod(x) qpow(x, mod - 2)

int f[505][505];

void solve(){
    int n, m;
    std::cin >> n >> m;
    int ans(0);
    std::vector<int>a(n + 1);
    for(int i(1); i <= m; i++) f[i][i] = i;
	for(int i(1); i <= n; i++) std::cin >> a[i], ans += m + 1 - a[i], ans %= mod;
	for(int i(2); i <= m; i++)
		for(int j(1); j <= i - 1; j++)
			f[i][j] = ((mod - mod / 2) * (f[i - 1][j] + f[i][j - 1])) % mod;
	for(int i(1); i < n; i++) ans = (ans - f[m + 1 - a[i]][m + 1 - a[i + 1]]) % mod, ans = (ans + mod) % mod;
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
