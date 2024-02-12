#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], b[200005], c[200005], e[200005], f[200005], ans[200005];
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        for (int i = 0; i < n + 1; ++i) {
            ans[i] = 0;
            e[i] = 0;
        }
        for (int i = 1; i <= n; ++i) cin >> a[i];//茶的量
        for (int i = 1; i <= n; ++i) cin >> b[i];//品茶能喝的量
        for (int i = 1; i <= n; ++i) {
            c[i] = c[i - 1] + b[i];
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += c[i - 1];
            int ff = upper_bound(c + 1, c + n + 1, a[i]) - c;
            e[ff]--; e[i]++;
            ans[ff] += a[i] - c[ff - 1];
        }
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + e[i];
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] += f[i] * b[i];
        }
        for (int i = 1; i < n; ++i)cout << ans[i] << ' ';
        cout << ans[n] << '\n';
    }
    return 0;
}