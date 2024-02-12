#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a = 1, b = 0;
        int flag = 1, k = 2;
        int i = 1;
        int dig = 0;
        while (1) {
            if (flag)b += k;
            else a += k;
            i += k, ++dig;
            if (dig == 2)dig = 0, flag = 1 - flag;
            if (i + k < n)k++;
            else break;
        }
        if (flag)b += n - i;
        else a += n - i;
        cout << a << ' ' << b << '\n';
    }
    return 0;
}