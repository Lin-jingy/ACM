#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a; cin >> a;
        int ans = n - 1;
        for (int i = 0; i < n - 2; ++i) {
            if (a[i] == a[i + 2])--ans;
        }
        cout << ans << '\n';
    }

    return 0;
}