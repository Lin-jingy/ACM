#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int s[2005];
vector<int>v;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    int x;
    for(int i = 0; i < n; ++ i){
        cin >> x;
        s[i] = x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++ i){
        v.erase(find(v.begin(), v.end(), s[i]));
        vector<int>a(v);
        for(int j = i + 1; j < n; ++ j){
            a.erase(find(a.begin(), a.end(), s[j]));
            int it = upper_bound(a.begin(), a.end(), s[j] - s[i]) - a.begin();
            ans += it;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
