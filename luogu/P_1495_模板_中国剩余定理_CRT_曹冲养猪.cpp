#include<bits/stdc++.h>

#define int long long

int Exgcd(int a, int b, int &x, int &y) {
    if (!b) {
      x = 1;
      y = 0;
      return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

void solve() {
    int n;
    std::cin >> n;
    int sum = 1;
    std::vector<int> a(n), b(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) std::cin >> a[i] >> b[i], sum *= a[i];
    for(int i = 0; i < n; ++i) {
        int m = sum / a[i];
        int x, y;
        Exgcd(m, a[i], x, y);
        ans += (b[i] * m * x + sum) % sum;
        ans = (ans + sum) % sum;
    }
    std::cout << ans << '\n';


    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}