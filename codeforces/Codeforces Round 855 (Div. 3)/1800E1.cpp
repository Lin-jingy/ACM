#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        if (a == b) { cout << "YES\n"; goto A; }
        if (n <= 3) { cout << "NO\n"; goto A; }
        else if (n == 4) {
            swap(a[0], a[3]); 
            if (a != b) { cout << "NO\n"; goto A; }
            else { cout << "YES\n"; goto A; }
        }
        else if (n == 5) {
            if (a[2] != b[2]) { cout << "NO\n"; goto A; }
            else {
                int p[26] = { 0 };
                for (int i = 0; i < n; ++i) {
                    p[a[i] - 'a']++; p[b[i] - 'a']--;
                }
                for (int i = 0; i < 26; ++i) {
                    if (p[i] != 0) { cout << "NO\n"; goto A; }
                }
                cout << "YES\n";
                goto A;
            }
        }
        else {
            int p[26] = { 0 };
            for (int i = 0; i < n; ++i) {
                p[a[i]-'a']++; p[b[i]-'a']--;
            }
            for (int i = 0; i < 26; ++i) {
                if (p[i] != 0) { cout << "NO\n"; goto A; }
            }
        }
 
        cout << "YES\n";
    A:;
    }
 
    return 0;
}