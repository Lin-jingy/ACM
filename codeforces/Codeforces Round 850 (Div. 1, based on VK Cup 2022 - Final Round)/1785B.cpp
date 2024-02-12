#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005] = { 0 }, b[100005] = { 0 };
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, w, h;
        cin >> n >> w >> h;
        for (int i = 1; i <= n; ++i)cin >> a[i];
        for (int i = 1; i <= n; ++i)cin >> b[i];
        pair<int, int> move = { INT_MIN,INT_MAX };
        for (int i = 1; i <= n; ++i) {
            int la = a[i] - w, lb = b[i] - h;
            int ra = a[i] + w, rb = b[i] + h;
            int k1 = la - lb, k2 = ra - rb;
            int mins = min(k1, k2);
            int maxs = max(k1, k2);
            if (mins > move.first)move.first = mins;
            if (maxs < move.second)move.second = maxs;
        }
        if (move.first <= move.second)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}