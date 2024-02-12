#include <bits/stdc++.h>

using namespace std;
const int N = 45;
int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    if (n%2==1) {
        int flag = 0, sz = 0;
        while (n) {
            a[++flag] = n & 1;
            n >>= 1;
        }
        --flag;
        for (int i = 1; i <= flag; ++i) {
            if (a[i + 1]) b[++sz] = 2;
            else b[++sz] = 1, a[i + 1] = 1;
        }
        cout << flag  << '\n';
        for (int i = sz; i > 0; --i) cout << b[i] << " \n"[i == 1];
        return;
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}