#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> a;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace(x, y);
    }
    int x = 0;
    int y = 0;
    for (char c : s) {
        if (c == 'R') x += 1;
        if (c == 'L') x -= 1;
        if (c == 'U') y += 1;
        if (c == 'D') y -= 1;
        h -= 1;
        if (h < 0) {
            cout << "No" << '\n';
            return;
        }
        auto it = a.find({x, y});
        if (it != a.end() && h < k) {
            h = k;
            a.erase(it);
        }
    }
    cout << "Yes" << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
