#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int a[2][N];
int pre[N], post[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[0][i];
    for(int i = 1; i <= n; ++ i)cin >> a[1][i], pre[i] = 0, post[i] = 0;
    pre[0] = 0, post[n + 1] = 0;
    for(int i = 1; i <= n; ++ i)pre[i] = pre[i - 1] + a[1][i];
    for(int i = n; i >= 1; -- i)post[i] = post[i + 1] + a[0][i];
    int mn = min(pre[n - 1], post[2]);
    for(int i = 2; i < n; ++ i){
        mn = min(mn, max(pre[i - 1], post[i + 1]));
    }
    cout << mn << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
