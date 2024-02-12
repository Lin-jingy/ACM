#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n, k;
    cin >> n >> k;
    int a = 1, ans = 0;
    while (n > a and k >= a) {
        a *= 2;
        ans ++;
    }
    cout << ans + (n - a + k - 1) / k << "\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
