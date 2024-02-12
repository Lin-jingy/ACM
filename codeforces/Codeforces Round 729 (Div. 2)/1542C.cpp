#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int mod = 1e9 + 7;

int lcm(int a, int b){return a / __gcd(a, b) * b;}

void solve(){
    int n;
    cin >> n;
    int k = 1;
    int ans = 0;
    for(int i = 2; ; ++i){
        ans = ans + (i * (n / k - n / lcm(k, i)) % mod) % mod;
        ans %= mod;
        k = lcm(k, i);
        if(k > n)break;
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
