#include<bits/stdc++.h>

using namespace std;
#define int long long 
using PII = pair<int, int>;
const int N = 5e5 + 5;
int a[N], p[N];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
		if(a[i] <= k)p[a[i]] ++;
	}
	for(int i = 1; i <= k; ++ i){
		if(p[i] >= i + 1){
			p[i + 1] += p[i] / (i + 1);
			p[i] %= i + 1;
		}
	}  
	for(int i = 1; i < k; ++ i){
		if(p[i] != 0){
			cout << "No";
			return;
		}
	}
	cout << "Yes";
	return;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}