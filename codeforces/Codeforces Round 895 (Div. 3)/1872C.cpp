#include<bits/stdc++.h>

void solve(){
    int l, r;
    std::cin >> l >> r;
    if (r < 4) std::cout << "-1\n";
    else if (l == r){
		for (int i = 2; i * i <= l; i++) if (!(l % i)) { 
            std::cout << i << ' ' << l - i << '\n'; 
            return; 
        }
		std::cout << "-1\n";
	}
    else std::cout << 2 << ' ' << r - 2 - (r % 2) << '\n';
}

int main(){
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}