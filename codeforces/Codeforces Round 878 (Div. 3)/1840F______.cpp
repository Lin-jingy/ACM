//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int n, m;
class node{
public:
    int t, op, pos;
    friend bool operator< (node a, node b){ 
        return a.t < b.t;
    }
}x[105];

bool dp[1005][1005];

void solve(){
    cin >> n >> m;
    for(size_t i(0); i <= n; ++i) for(size_t j(0); j <= m; ++j) dp[i][j] = false;
    int r;
    cin >> r;
    for(size_t i(1); i <= r; ++i) cin >> x[i].t >> x[i].op >> x[i].pos;
    sort(x + 1, x + 1 + n);


}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
