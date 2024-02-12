#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
signed main() {
    quick;
    int t; cin >> t;
    while (t--) {
        int k, n; cin >> k >> n;
        cout << k << ' ' << (n + 1) / 2 << '\n';
        int x;
        priority_queue<int>l;
        priority_queue<int, vector<int>, greater<>>r;
        cin >> x;
        int mid = x;
        cout << mid;
        int flag = 1;
        for (int i = 2; i <= n; ++i) {
            cin >> x;
            if (x > mid)r.push(x);
            else l.push(x);
            if (i % 2 == 1 and l.size() > r.size()) {
                r.push(mid);
                mid = l.top();
                l.pop();
            }
            else if (i % 2 == 1 and l.size() < r.size()) {
                l.push(mid);
                mid = r.top();
                r.pop();
            }
            if (i % 2 == 1 && flag % 10 != 0) { cout << ' ' << mid; ++flag; }
            else if (i % 2 == 1) { cout << mid; ++flag; }
            if (flag % 10 == 0 && i % 2 == 1 && (flag != (n + 1) / 2))cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}