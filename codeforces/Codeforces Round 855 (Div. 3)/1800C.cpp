#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        priority_queue<int>a;
        int n; cin >> n;
        int x;
        int sum0 = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x == 0) {
                if (!a.empty()) {
                    ans += a.top();
                    a.pop();
                }
            }
            else {
                a.push(x);
            }
        }
        cout << ans << '\n';

    }

    return 0;
}