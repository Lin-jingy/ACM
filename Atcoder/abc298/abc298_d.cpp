#include<bits/stdc++.h>

#define int long long 
const int mod = 998244353;
std::queue<int>qe;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve(){
    qe.push(1);
    int q;
	std::cin >> q;
	int ans = 1;
	while (q--) {
		int op, x;
        std::cin >> op;
		if (op == 1) {
			std::cin >> x;
			qe.push(x);
			ans = (ans * 10 % mod + x) % mod;
		} else if (op == 2) {
			ans = (ans - qe.front() * qpow(10, (int)qe.size() - 1ll) % mod + mod) % mod;
			qe.pop();
		} else {
			std::cout << ans <<'\n';
		}
	}

}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}