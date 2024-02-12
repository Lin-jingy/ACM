#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        int p1[26] = { 0 }, p2[26] = { 0 };
        int ans = 0;
        int n, k; cin >> n >> k;
        string a; cin >> a;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 'a' and a[i] <= 'z') {
                p1[a[i] - 'a']++;
            }
            else if (a[i] >= 'A' and a[i] <= 'Z') {
                p2[a[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            int mins = min(p1[i], p2[i]), maxs = max(p1[i], p2[i]);
            int mid = min(k, (maxs - mins) / 2);
            ans += mins + mid, k -= mid;
        }
        cout << ans << '\n';
    }

    return 0;
}