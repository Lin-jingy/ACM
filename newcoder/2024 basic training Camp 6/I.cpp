#include <bits/stdc++.h>

#define int long long
constexpr int N = 1e5 + 5;
int a[N], b[N];

int find_max(int *a, int n) {
    int ans = a[1];
    int sum = 0;
	for (int i = 1; i <= n; ++i){
		if(sum >= 0) {
            sum += a[i];
        } else {
            sum = a[i];
        }
		ans = std::max(ans, sum);
	}
    return ans;
}
int find_min(int *a, int n) {
    int ans = a[1];
    int sum = 0;
	for (int i = 1; i <= n; ++i){
		if(sum <= 0) {
            sum += a[i];
        } else {
            sum = a[i];
        }
		ans = std::min(ans, sum);
	}
    return ans;
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= m; ++i) std::cin >> b[i];
    int maxa = find_max(a, n), maxb = find_max(b, m);
    int mina = find_min(a, n), minb = find_min(b, m);
    std::cout << std::max({maxa * maxb, maxa * minb, mina * maxb, mina * minb});
    return 0;
}