#include<bits/stdc++.h>
 
using namespace std;
#define int long long 
 
void solve(){
	int a, b, n;
	cin >> a >> b >> n;
	int ans = 0;
	while(a <= n and b <= n){
		if(a > b)swap(a, b);
		a += b;
		++ans;
	}
	cout << ans << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t ;
	cin >> t;
	while(t--)solve();
	return 0;
}