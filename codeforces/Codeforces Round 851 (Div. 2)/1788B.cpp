#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 1) {
            string a = to_string(n);
            int k = a.size();
            int l = 0, r = 0;
            int flag = 1;
            int m = 0, x = 0;
            for (int i = 0; i < k; ++i) {
                m = a[i] - '0';
                x = m / 2;
                if (m % 2 == 1) {
                    if (flag == 1) { l = l * 10 + x; r = r * 10 + x + 1; --flag; }
                    else if (flag == 0) { l = l * 10 + x + 1; r = r * 10 + x; ++flag; }
                }
                else {
                    l = l * 10 + x;
                    r = r * 10 + x;
                }
            }
            cout << l << ' ' << r << '\n';
        }
        else cout << n / 2 << ' ' << n / 2 << '\n';
    }
    return 0;
}