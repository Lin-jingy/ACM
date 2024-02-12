#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int a[N], p[N];
void solve(){
	int n, q;cin >> n >> q;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	for(int i = 3; i <= n; i ++)if(a[i] <= a[i-1] and a[i-1] <= a[i-2]) p[i]++;
	for(int i = 1; i <= n; i ++)p[i] += p[i-1];
	while(q--){
		int l, r;cin >> l >> r;
		if(l == r)cout << 1 << '\n';
		else if(r - l == 1)cout << 2 << '\n';
		else{
			int ans = 2;
			ans = max(ans, r - l + 1 - (p[r] - p[l+1]));
			cout << ans << '\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
	return 0;
}