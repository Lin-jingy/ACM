#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        int p[4] = { 0 };
        int n; cin >> n;
        string a;
        cin >> a;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 'A' and a[i] <= 'Z')a[i] -= 'A' - 'a';
            if (a[i] == 'm')p[0]++;
            else if (a[i] == 'e')p[1]++;
            else if (a[i] == 'o')p[2]++;
            else if (a[i] == 'w')p[3]++;
        }
        for (int i = 0; i < 4; ++i) {
            if (p[i] == 0) { cout << "NO\n"; goto A; }
        }
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]);
            else {
                if (a[i - 1] == 'm' and a[i] == 'e');
                else if (a[i - 1] == 'e' and a[i] == 'o');
                else if (a[i - 1] == 'o' and a[i] == 'w');
                else { cout << "NO\n"; goto A; }
            }
        }
        cout << "YES\n";
    A:;
    }

    return 0;
}