#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N=105;
const int M=105;
int n,a[N],dep[N];

void dfs(int l, int r, int depth){
	if (l > r) return;
	int pos = l;
	for (int i = l; i <= r; i++)if (a[i] > a[pos]) pos = i;
	dep[pos] = depth;
	dfs(l, pos - 1, depth + 1);
	dfs(pos + 1, r, depth + 1);
}

void solve(){
    cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
		dfs(1, n, 0);
		for (int i = 1; i <= n; i++)cout << dep[i] << " \n"[i == n];
}

signed main(){
	int t;
    cin >> t;
    while(t--)solve();
	return 0;
}