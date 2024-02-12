#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 5;
int a[N], p[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    for(int i = 1; i <= n; ++ i)p[i] = a[i] ^ p[i - 1];
    int ans = n * (n + 1) / 2;
    for(int i = 1; i <= n; ++ i){
        vector<int>v;
        for(int j = 0; j * j < 2 * n; ++ j){
            if(p[i] ^ (j * j) < 2 * n)ans --;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
