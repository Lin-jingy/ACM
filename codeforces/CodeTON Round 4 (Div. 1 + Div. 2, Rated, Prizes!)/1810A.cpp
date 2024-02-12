#include <algorithm>
#include <iostream>

#define int long long
using namespace std;
int a[100005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= i and a[i] > 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}