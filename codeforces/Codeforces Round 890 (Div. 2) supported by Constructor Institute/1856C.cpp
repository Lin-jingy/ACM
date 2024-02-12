#include<bits/stdc++.h>

void solve(){
    int n, k, mx = 0;
    std::cin >> n >> k;
    std::vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], mx = std::max(mx, a[i]);
    int l = mx, r = mx + n, ans;
    auto check = [&](int x) -> int{
        int tmp = k;
	    for( int i = 1 ; i <= n ; i ++ ){
		    tmp = k;
		    for( int j = i ; j <= n ; j ++ ){
			    if( a[j] < x - ( j - i ) ){
				    if( tmp < ( x - j + i - a[j] ) ) break;
				    tmp -= ( x - j + i - a[j] );
			    }
			    else return 1;
		    }
	    }
	    return 0;
    };
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}