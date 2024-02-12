#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"


void solve(){
    int n;
    cin >> n;
    unordered_map<int, int>mp;
    for(int i = 1, x; i <= n; ++i) cin >> x, mp[x]++;
    int ans = 6;
    int s = 10 - mp.size();
    for(int i = s; i >= s - 1; --i) ans *= i;
    ans /= 2;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
