#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int q;
    cin >> q;
    int x, a, b, n;
    pair<int, int> h;
    int flag = 0;
    while (q--) {
        cin >> x;
        if (x == 1) {
            cin >> a >> b >> n;
            int mid = (n - 1) * (a - b);
            if (!flag) {
                h.first = mid;
                h.second = mid + a;
                flag = 1;
                cout<<1<<' ';
            } else {
                if (mid <= h.second or mid + a >= h.first) {
                    h.first = max(h.first, mid);
                    h.second = min(h.second, mid + a);
                    cout << 1 << ' ';
                } else cout << 0 << ' ';
            }

        } else {
            cin >> a >> b;
            int mn = (h.first - a) / (a - b) + 1;
            int mx = (h.second - a) / (a - b) + 1;
            if(mx==mn)cout<<mx<<' ';
            else cout<<-1<<' ';
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}