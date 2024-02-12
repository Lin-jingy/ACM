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


const int N = 2e5 + 5;
string s;
int a[N];

void solve(){
	int n;
	cin >> n;
	cin >> s;
    s = '0' + s;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i];
	}
	int mi = INF;
	for (int i = n; i >= 1; i--){
		mi = min(mi, a[i]);
		if (s[i] == '0'){
			ans -= mi;
			mi = INF;
		}
	}
	cout << ans << '\n';
	return;
}

signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
