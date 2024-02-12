#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int n, m;
string s[15];
int id[15];

bool check() {
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += (s[id[i]][j] != s[id[i + 1]][j]);
		}
		if (cnt != 1) {
			return 0;
		}
	}
	return 1;
}

void solve(){
    cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		id[i] = i;
	}
	do {
		if (check()) {
			yes;
			return;
		}
	} while (next_permutation(id + 1, id + 1 + n));
	no;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
