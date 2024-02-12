//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int n, k;

int check(int f1, int f2, int k){
	for (int i = k - 1; i >= 1; i--){
		int f0 = f2 - f1;
		if (f0 < 0 or f0 > f1 or f1 > f2) return 0;
		f2 = f1;
		f1 = f0;
	}
	return 1;
}

void solve(){
	cin >> n >> k;
	if (k > 50){
        cout << 0 << '\n';
        return;
    }
	int ans = 0;
    int kk = n;
	for (int i = 0; i <= kk; i++) ans += check(i, kk, k - 2), --kk;
	cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
