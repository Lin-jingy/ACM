#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        bool a[1005] = { false };
        int n; cin >> n;
        int x, k = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x == 2) { a[i] = true; ++k; }
        }
        if (k % 2 == 1) { cout << "-1\n"; continue; }
        k /= 2;
        int j = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i])++j;
            if (j == k) { cout << i + 1 << '\n'; goto A; }
        }
        cout << "-1\n";
    A:;
    }
    return 0;
}