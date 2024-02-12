#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a;
    unordered_map<int, int> mp;
    int x;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (!mp.count(x))a.push_back(x);
        mp[x]++;
    }
    sort(a.begin(), a.end());
    ans = n * c + d;
    for (int i = 0; i < (int) a.size(); ++i) {
        int sz = a[i];
        int mid;
        if (n - i - 1 >= 0)mid = (sz - i - 1) * d + (n - i - 1) * c;
        else mid = (sz - i - 1) * d;
        ans = min(ans, mid);

    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}