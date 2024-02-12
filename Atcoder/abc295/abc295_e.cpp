#include<bits/stdc++.h>

#define int long long 
using namespace std;

const int N = 2010;
const int mod = 998244353;

int qmi(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

signed main(){
	int n, m, k;	
    cin >> n >> m >> k;
    std::vector<int>fac(N), inv(N), s(N), z(N);
    std::vector<std::vector<int>>c(N, std::vector<int>(N));
    // fac[0] = fac[1] = 1;
    // for (int i = 2; i <= N - 2; i++) fac[i] = fac[i - 1] * i % mod;
    // inv[1] = 1;
    // for (int i = 2; i <= N - 2; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[0] = 1, inv[0] = 1;
	for(int i(1); i < N; i++) fac[i] = fac[i-1] * i % mod;
	inv[N-1] = qmi(fac[N-1] , mod - 2);
	for(int i(N - 2); i >= 1; i--)inv[i] = inv[i+1] * (i + 1) % mod;

    auto C = [&](int a,int b){
    	if(a<b) return 0ll;
    	return fac[a] * inv[b] % mod * inv[a - b] % mod;
    };

	for(int i(1), x; i <= n; i++)cin >> x, s[x]++;
	int w(s[0]);
	s[0] = 0;
	for(int i(1); i <= m; i++) s[i] = (s[i] + s[i-1]) % mod;
	int ans(0);
	for(int i(1); i <= m; i++){
		z[0] = 1;
		for(int j(1); j <= w; j++) z[j] = z[j-1] * (m - i + 1) % mod;
		int t = 1;
		for(int x = 0; x<=w and x <= k - 1 - s[i-1]; x++){
			ans = (ans + C(w, x) * t % mod * z[w - x] % mod)%mod;
			t = t * (i - 1) % mod;
		}
	}
	int mm = qmi(m, w) % mod;
	ans = ans * qmi(mm, mod - 2) % mod;
	cout << ans << '\n';
}