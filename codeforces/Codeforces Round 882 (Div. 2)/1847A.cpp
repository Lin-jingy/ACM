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

int a[105];
int n, k;

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    vector<int>v;
    for(int i = 2; i <= n; ++i) v.push_back(abs(a[i] - a[i - 1]));
    sort(v.begin(), v.end());
    --k;
    while(k--)v.pop_back();
    for(auto i:v) ans += i;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
