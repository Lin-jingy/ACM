#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[200005];
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i)cin >> a[i];
        int l = 0, r = n - 1;
        int min = 1, max = n;
        while (l < r) {
            if (a[l] == min)++l, ++min;
            else if (a[r] == max)--r, --max;
            else if (a[l] == max)++l, --max;
            else if (a[r] == min)--r, ++min;
            else break;
        }
        if (l == r)cout << "-1\n";
        else cout << l + 1 << ' ' << r + 1 << '\n';
    }
    return 0;
}