#include <bits/stdc++.h>

#define int long long
constexpr int mod = 998244353;

static long long Reverse_pair(std::vector<int> &a, int begin, int end) { // 1~n
    long long ans = 0;
    std::vector<int> c(a.size() + 1);
    auto msort = [&](auto &&self, int b, int e) {
        if(b == e)return;
        int mid = (b + e) / 2, i = b, j = mid + 1, k = b;
        self(self, b, mid);
        self(self, mid + 1, e);
        while(i <= mid && j <= e)
        	if(a[i] <= a[j]) c[k++] = a[i++];
        	else c[k++] = a[j++], ans += mid - i + 1;//统计答案
        while(i <= mid) c[k++] = a[i++];
        while(j <= e) c[k++] = a[j++];
        memcpy(&a[b], &c[b], sizeof(int) * (e - b + 1));
    };
    msort(msort, begin, end);
    return ans;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n), q(k);
    for(int &i:p) std::cin >> i;
    for(int &i:q) std::cin >> i;
    int ans = n * Reverse_pair(q, 0, k - 1) % mod;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}