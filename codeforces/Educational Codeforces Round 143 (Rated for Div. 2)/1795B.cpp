#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int b = 0, c = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int l, r; cin >> l >> r;
            if (l <= k && r >= k) {
                ++s;
                if (k - 1 >= l)++b;
                if (k + 1 <= r)++c;
            }
        }
        if (b == s || c == s || s == 0)cout << "NO\n";
        else cout << "YES\n";
    A:;
    }
    return 0;
}