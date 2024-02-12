#include<bits/stdc++.h>

using namespace std;
#define int long long
int ans;

class node{
public:
	int k;
	node *l;
	node *r;
};

node *a[1000005];

void add(int k, int l, int r){
	node *p = a[k];
	if(p == nullptr){
		p = new node;
		p -> l = nullptr;
		p -> r = nullptr;
		a[k] = p;
	}
	if(l != 0){
		if(a[l] == nullptr) {
			a[l] = new node;
			a[l] -> l = nullptr;
			a[l] -> r = nullptr;
		}
		node *x = a[l];
		x -> k = l;
		p -> l = x;
	}
	if(r != 0){
		if(a[r] == nullptr) {
			a[r] = new node;
			a[r] -> l = nullptr;
			a[r] -> r = nullptr;
		}
		node *y = a[r];
		y -> k = r;
		p -> r = y;
	}
}

void dfs(node *p, int d){
	if(p -> l != nullptr)dfs(p -> l, d + 1);
	if(p -> r != nullptr)dfs(p -> r, d + 1);
	ans = max(ans, d);
}

void solve(){
	int n; cin >> n;
	int l, r;
	cin >> l >> r;
	node *p = new node;
	p -> l = nullptr;
	p -> r = nullptr;
	p -> k = 1;
	a[1] = p;
	add(1, l, r);
	for(int i = 2; i <= n; ++i){
		cin >> l >> r;
		add(i, l, r);
	}
	dfs(p, 1);
	cout << ans;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}