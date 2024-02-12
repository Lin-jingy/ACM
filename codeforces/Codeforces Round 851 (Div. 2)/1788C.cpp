#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 0)cout << "NO\n";
        else {
            cout << "YES\n";
            int a = n / 2 + 1;
            int b = 2 * n;
            while (a) {
                cout << a << ' ' << b << '\n';
                --a, --b;
            }
            a = n;
            while (b > n) {
                cout << a << ' ' << b << '\n';
                --a, --b;
            }
        }
    }
    return 0;
}