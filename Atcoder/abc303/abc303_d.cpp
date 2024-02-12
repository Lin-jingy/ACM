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

const int N = 3e5 + 5;
int dp[N][2];


void solve(){
    int x, y, z;
    cin >> x >> y >> z;
    string a;
    cin >> a;
    a = 'a' + a;
    int ans = 0;
    dp[0][1] = 0;
    dp[0][0] = -inf;
    //for(int i = 1; i < a.size(); ++i)dp[i][1] = dp[i][0] = -inf;
    for(int i = 1; i < a.size(); ++i){
        if(a[i] == 'A'){
            dp[i][1] = min(dp[i - 1][1] + min(x, z + z + y), dp[i - 1][0] + min(x + z, y + z));
            dp[i][0] = min(dp[i - 1][0] + min(y, z + z + x), dp[i - 1][1] + min(y + z, x + z));
        }else{
            dp[i][1] = min(dp[i - 1][1] + min(y, z + z + x), dp[i - 1][0] + min(y + z, x + z));
            dp[i][0] = min(dp[i - 1][0] + min(x, z + z + y), dp[i - 1][1] + min(z + x, y + z));
        }
    }
    cout << min(dp[a.size() - 1][1], dp[a.size() - 1][0]) + inf << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
