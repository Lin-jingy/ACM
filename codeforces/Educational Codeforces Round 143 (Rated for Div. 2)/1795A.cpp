#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b;
        char flag;
        cin >> a >> b;
        int len = a + b;
        string x, sa;
        cin >> x >> sa;
        reverse(sa.rbegin(), sa.rend());
        x += sa;
        int sum = 0;
        flag = x[0];
        for (int i = 1; i < len; ++i) {
            if (flag == 'B' && x[i] == 'B') {
                ++sum;
            }
            else if (flag == 'R' && x[i] == 'R') {
                ++sum;
            }
            flag = x[i];
        }
        if (sum <= 1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}