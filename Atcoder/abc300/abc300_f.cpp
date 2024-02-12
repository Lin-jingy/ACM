#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

int n, m, k;
string s;
void solve() {
    cin >> n >> m >> k >> s;
    vector<int> p;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'x') p.push_back(i);
    }
    int cnt = p.size();
    int x = m * cnt;
    if (x == k){
        cout << n * m;
        return;
    }
    int ans = 0;
    ans = max(ans, n * (k / cnt) + p[k % cnt]);
    ans = max(ans, n * (k / cnt) + (n - 1 - p[cnt - 1 - k % cnt])); 
    for (int i = 0; i < cnt; i ++) {
        if (k + i + 1 < x) {
            ans = max(ans, p[(k + i + 1) % cnt] + n * ((k + i + 1) / cnt) - p[i] - 1);
        }
    }
    cout << ans ;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
