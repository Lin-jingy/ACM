//#pragma GCC optimize(3)
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
    vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if(abs(sum) % 2 == 1){
        cout << -1 << '\n';
        return;
    }
    int flag = 1;
    if(sum < 0) flag = -1;
    int k = abs(sum) / 2;
    vector<bool>p(n + 1, false);
    p[0] = true;
    for(int i = 1; i <= n and k > 0; ++i){
        if(a[i] == flag and p[i - 1] == false) p[i] = true, --k;
    }
    vector<PII>ans;
    for(int i = 1; i <= n; ++i){
        if(i != n and p[i + 1] == true) ans.push_back({i, i + 1}), ++i;
        else ans.push_back({i, i});
    }

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i.first << ' ' << i.second << '\n';
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
