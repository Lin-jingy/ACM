#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b, m, n;
        cin >> a >> b >> n >> m;
        double ca = a * m * 1.0 / (m + 1);
        if (ca <= b) {
            int k = n / (m + 1);
            int mk = n % (m + 1);
            cout << k * a * m + mk * min(a, b) << '\n';
        }
        else {
            cout << n * b << '\n';
        }

    }
    return 0;
}