#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[200005], b[200005];
bool p[200005];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        for (int j =  1; j * a[i] <= 200000; ++j) {
            if (b[j * a[i]])p[j] = 1;
        }
    }
    while (q--) {
        cin >> x;
        if (p[x])cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}