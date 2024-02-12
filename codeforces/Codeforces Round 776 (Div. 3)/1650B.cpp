#include<bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int l, r, a;
    cin >> l >> r >> a;
    int ans = r / a + r % a;
    int v = (r + 1) / a * a - 1;
    if (v >= l) ans = max(ans, v / a + v % a);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
}