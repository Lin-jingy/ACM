#include<bits/stdc++.h>

#define int long long
const int mod = 9901;

int qpow(int a,int b){
	int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return sum;
}


signed main(){
    int a, b;
    std::cin >> a >> b;
    int ans = 1;
    for(int i = 2; i <= a; ++i){
		if(a % i == 0){
			int k = 0;
			while(a % i == 0) ++k, a /= i; 
			if(i % mod == 1) ans = ans * (k + 1) % mod;
			else ans = ans * ((qpow(i, k * b + 1) - 1) % mod * qpow(i - 1, mod - 2) % mod) % mod;
		}
	}
    if(a != 1) {
        if(a % mod == 1) ans = ans * 2 % mod;
		else ans = ans * ((qpow(a, b + 1) - 1) % mod * qpow(a - 1, mod - 2) % mod) % mod;
    }
    std::cout << (ans + mod) % mod << '\n';
}