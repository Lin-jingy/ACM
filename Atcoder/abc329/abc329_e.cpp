#include<bits/stdc++.h>

int main() {
    int n, m;
    std::string s, t;
	std::cin >> n >> m >> s >> t;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(m));
	dp[0][m - 1] = (s[0] == t[0]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!dp[i][j]) continue;
			if(i + m < n && s[i + 1] == t[0]) dp[i + 1][m - 1] = true;
			if(j > 0 && s[i + 1] == t[m - j]) dp[i + 1][j - 1] = true;
			if(j == 0) for(int k = 0; k < m; k++) if(s[i + 1] == t[k]) dp[i + 1][m - k - 1] = true;
		}
	}
    std::cout << (dp[n - 1][0] ? "Yes" : "No");
}