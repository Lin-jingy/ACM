#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 10;
double dp[N];
int n, m;

void solve(){
    int x, y;
    unordered_map<int, int>mp;
    for(int i = 1; i <= m; ++i){
        cin >> x >> y;
        mp[x] = y;
    }
    for(int i = 0; i < n + 10; ++ i)dp[i] = 0;
    for(int i = n - 1; i >= 0; --i){
        if(mp.count(i))dp[i] = dp[mp[i]];
        else {
            for(int j = 1; j <= 6; ++j) dp[i] += 1.0 / 6 * dp[i + j];
            dp[i] += 1;
        }
        
    }
    printf("%.4lf\n", dp[0]);
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >> n >> m, m + n)solve();
    return 0;
}
