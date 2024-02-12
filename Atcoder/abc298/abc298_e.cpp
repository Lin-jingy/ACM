#include<bits/stdc++.h>
#include<unordered_map>

#define int long long 
using namespace std;
const int mod = 998244353;

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

inline int rmod(int x){return qpow(x, mod - 2);}

int dp[105][105][2];//1为先走，0为后走

void solve(){
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    int rp = rmod(p), rq = rmod(q);
    for(int i = 1; i <= n; ++ i)for(int j = 0; j <= 1; ++ j)dp[n][i][j] = 1;//初始化
    for(int i = n - 1; i >= 1; -- i){
        for(int j = n - 1; j >= 1; -- j){
            for(int k = 1; k <= p; ++ k)dp[i][j][0] += dp[min(n, i + k)][j][1];
            dp[i][j][0] *= rp;
            dp[i][j][0] %= mod;
            for(int k = 1; k <= q; ++ k)dp[i][j][1] += dp[i][min(n, j + k)][0];
            dp[i][j][1] *= rq;
            dp[i][j][1] %= mod;

        }
    }
    cout << dp[a][b][0] << '\n';
}

signed main(){
    solve();
    return 0;
}