#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
#define for(x, n, k) for(int i = x; (int)i <= n; (int)i += k)
const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(1, n, 1)cin >> a[i];   
    int ans = 0;
    for(1, n, 2)ans += a[i];
    vector<int>x, y;
    for(2, n, 2)x.push_back(a[i] - a[i - 1]);
    int sum = 0;
    int k = 0;
    for(0, (int)x.size() - 1, 1){
        sum += x[i];
        sum = max(sum, 0ll);
        k = max(k, sum);
    }
    sum = 0;
    for(3, n, 2)y.push_back(a[i - 1] - a[i]);
    for(0, (int)y.size() - 1, 1){
        sum += y[i];
        sum = max(sum, 0ll);
        k = max(k, sum);
    }
    cout << ans + k << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
