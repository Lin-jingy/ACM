#include<bits/stdc++.h>

struct node {
	int l, r, val, lnum;
}p[10000000];
constexpr int N = 2e5 + 10;
int ver[N], f = 0;

int build(int l, int r) {
	int root = ++f;
	if(l == r) return root;
	int mid = (l + r) >> 1;
    p[root].l = build(l, mid);
    p[root].r = build(mid + 1, r);
    return root;
}



signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	std::vector b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	ver[0] = build(1, n);
	for(int i = 1; i <= m; ++i) {
		int l, r, k;
		std::cin >> l >> r >> k;
	}

	return 0;
}