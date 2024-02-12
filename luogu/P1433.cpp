#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX;
#define yes cout << "Yes\n"
#define no cout << "No\n"

pair<double, double> p[20];
int n;
double dp[20][1ll << 16];

inline double dis(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

void solve(){
    cin >> n;
    int x, y;
    for(int i = 1; i <= n; ++i) 
        cin >> p[i].first >> p[i].second;
    int len = 1ll << n;
    for(int i = 0; i < len; ++i) for(int j = 1; j <= n; ++j)dp[j][i] = inf;
    for(int i = 1; i <= n; ++i) dp[i][1 << (i - 1)] = dis(p[i], {0, 0});
    for(int i = 0; i < len; ++i){
        for(int j = 1; j <= n; ++j){
            if((i >> (j - 1)) & 1){
                for(int k = 1; k <= n; ++k){
                    if(j == k)continue;
                    if((i >> (k - 1)) & 1)
                        dp[j][i] = min(dp[j][i], dp[k][i - (1ll << (j - 1))] + dis(p[k], p[j]));
                }
            }
        }
    }
    double ans = inf;
    for(int i = 1; i <= n; ++i) 
        ans = min(ans, dp[i][len - 1]);
    printf("%.2lf", ans);
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
