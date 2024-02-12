#include<bits/stdc++.h>

const int N = 1e6 + 5;
long long dp[N];

int main(){
	int k = 0;
	for (int i = 1; k <= 1e6; i++){
		for (int j = 0; j < i and k <= 1e6; j++){
			k++;
			dp[k] = (long long)k * k;
			if (j != 0) dp[k] += dp[k - i];
			if (j != i - 1) dp[k] += dp[k - i + 1];
			if ((j != 0) and (j != i - 1)) dp[k] -= dp[k - i - i + 2];
		}
    }
    int T;
	std::cin >> T;
	while(T--){
        int n;
        std::cin >> n;
		std::cout << dp[n] << '\n';
	}
    return 0;
}