#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i)cin >> a[i];
        sort(a + 1, a + n + 1);
        int k = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == k + 1)k++;
            else if (a[i] > k)ans += (a[i] - k - 1), ++k;
        }
        cout << ans << '\n';
    }
    return 0;
}