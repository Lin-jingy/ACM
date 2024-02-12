#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int pr1[105], pr2[105];

void solve(){
    int n, m, x;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> x, pr1[i] = pr1[i - 1] + x;
    cin >> m;
    for(int i = 1; i <= m; ++ i)cin >> x, pr2[i] = pr2[i - 1] + x;
    int mx = 0;
    for(int i = 0; i <= n; ++ i)for(int j = 0; j <= m; ++ j)mx = max(mx, pr1[i] + pr2[j]);
    cout << mx << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

/*
1
10
-2 -4 0 0 -4 3 -1 -1 -1 -1
4
1 4 4 -2
*/