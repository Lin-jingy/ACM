#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int qpow(int b){
	int a = 10;
	int sum = 1;
	while(b){
		if(b & 1)sum = sum * a;
		b >>= 1;
		a *= a;
	}
	return sum;
}

void solve(){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	if(c < b or c < a){
		cout<< -1 << '\n';
		return;
	}
	if(c - b - 1 <= 0 or c - a - 1 <= 0){
		int n = qpow(a - 1);
		int l = qpow(c - 1),r = qpow(c) - 1;
		int mn = qpow(b - 1),mx = qpow(b) - 1;
		n = max(n, 1ll);
		l = max(l, 1ll);
		mn = max(mn, 1ll);
		for(int i = n; i < n * 10; i++){
			if(i + mx >= l and i + mn <= r){
				int sum = min(i + mx, r) - max(i + mn, l)+1;
				if(sum >= k){
					int rk = max(i + mn, l) + k - 1 - i;
					int rm = max(i + mn, l) + k - 1;
					cout << i << " + " << rk << " = " << rm << '\n';
					return;
				}
				k -= sum;
			}
		}
	}
	cout << -1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
