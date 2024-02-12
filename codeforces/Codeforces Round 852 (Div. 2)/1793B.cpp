#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 1 << '\n' << x << '\n';
            continue;
        }
        else if (x - y == 1) {
            cout << 2 << '\n' << x << ' ' << y << '\n';
            continue;
        }
        cout << (x - y + 1) * 2 - 2 << '\n';
        for (int i = x; i >= y; --i)cout << i << ' ';
        for (int i = y + 1; i < x - 1; ++i)cout << i << ' ';
        cout << x - 1 << '\n';
    }
    return 0;
}