#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[100005]={0}, sum = 0;
        for (int i = 0; i < n; ++i) { cin >> a[i]; sum += a[i]; }
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == -1 and a[i + 1] == -1) { cout << sum + 4 << '\n'; goto A; }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] + a[i + 1] == 0) { cout << sum << '\n'; goto A; }
        }
        cout << sum - 4 << '\n';
    A:;
    }
    return 0;
}