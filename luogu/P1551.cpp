#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
int fi[5005];
int find(int x) {
    return x == fi[x] ? x : fi[x] = find(fi[x]);
}
bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return false;
    else fi[x] = y;
    return true;
}
bool isSame(int x, int y) {
    return find(x) == find(y);
}
signed main() {
    quick;
    int n, m, p; cin >> n >> m >> p;
    int x, y;
    for (int i = 0; i <= n; ++i)fi[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        join(x, y);
    }
    while (p--) {
        cin >> x >> y;
        if (isSame(x, y))cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}