#include <bits/stdc++.h>

#define int long long
const int N = 3010;
int a[N], pre[N][N], suf[N][N], ans[N], vis[N];

void solve(){
    std::string s;
    int n, k;
    std::cin >> n >> k >> s;
    memset(ans, 0, sizeof(int) * (n + 10));
    memset(vis, 0, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
	a[n + 1] = 0;
	for (int i = 0; i <= k; i++) suf[n + 1][i] = 0;
	for (int i = 1; i <= n; i++){
		int now = 0, x = i - 1;
		for (int j = 0; j <= k; j++){
			while (now < j + 1 and x <= n){
				x++;
				if (a[x] == 0) now++;
			}
			suf[i][j] = x - i;
		}
	}
	for (int i = n; i >= 1; i--){
		for (int j = 0; j <= k; j++){
			suf[i][j] = std::max(suf[i][j], suf[i+1][j]);
		}
	}
	for (int i = n; i >= 1; i--){
		int now = 0, x = i+1;
		for (int j = 0; j <= k; j++){
			while (now < j + 1 and x >= 1){
				x--;
				if (a[x] == 0) now ++;
			}
			pre[i][j] = i - x;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			pre[i][j] = std::max(pre[i][j], pre[i-1][j]);
		}
	}
	vis[0] = 1;
	ans[0] = std::max(pre[n][k], suf[1][k]);
	for (int i = 1; i <= n; i++){
		int tot = 0;
		for (int j = i; j <= n; j++){
			if (a[j] == 1) tot ++;
			if (tot > k) break;
			ans[j-i+1] = std::max(ans[j-i+1], suf[j+1][k-tot]);
			ans[j-i+1] = std::max(ans[j-i+1], pre[i-1][k-tot]);
			vis[j-i+1] = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		int now = 0;
		for (int j = 0; j <= n; j++){
			if (!vis[j]) continue;
			now = std::max(now, i * j + ans[j]);
		}
		std::cout << now << ' ';
	}
	std::cout << '\n';

}

signed main(){
    int T = 1;
	std::cin >> T;
	while (T--) solve();
	return 0;
}