#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int lcm(int x, int y){return x * y / __gcd(x, y);}

void solve(){
    int n, x, ans = 1;
    cin >> n;
    while(n--){
        cin >> x;
        ans = lcm(x, ans);
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
