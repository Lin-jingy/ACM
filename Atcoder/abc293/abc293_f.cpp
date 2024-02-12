#include<bits/stdc++.h>
#define int __int128

int check(int mid, int B){
	int ans(0), base(1); 
	for(int i(0);i < 6; i++){
		if((1 << i) & B){
			ans += base;
			if(ans > 1e18) return 2e18;
		} 
		if(base > 1e18 / mid) base = 2e18;
		else base *= mid;
	}
	return ans;
}

signed main(){
	long long T;
	std::cin >> T;
	while(T--){
		long long ans=0, n;
		std::cin >> n;
		for(int i(2);i <= std::min(n, 1000ll); i++){
			int tmp(n);
			while(tmp){
				if(tmp%i>1)goto A;
				tmp/=i;
			}
			ans++;
            A:;
		} 
		if(n<=1000) std::cout<<ans<<'\n';
		else{
			for(int i =(1 << 6) - 1; i >= 0; i--){
				int l(0), r(n), as(0);
				while(l <= r){
					int mid = (l + r) >> 1;
					if(check(mid, i) >= n) r = mid - 1, as = mid;
					else l = mid + 1;
				}
				if(check(as, i) == n and as > 1000) ans++;
			}
			std::cout << ans << '\n';
		}
	}
} 