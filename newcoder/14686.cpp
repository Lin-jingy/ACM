#include<bits/stdc++.h>

#define int long long 
#define i128 __int128

int n, m, ans;
std::vector<int>a;


signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    
    for(int i = 0, x; i < n; ++i){
        std::cin >> x;
        a.push_back(x);
    }

    for(int i = 1; i < (1<<n); i++){
		int x = m, num = 0;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)) {
				num++;
				x /= a[j];
			}
		}
		if(num & 1) ans += x;
		else ans -= x;
	}

    std::cout << ans << '\n';

    return 0;
}