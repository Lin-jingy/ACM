#include<bits/stdc++.h>

using namespace std;
#define int long long 
using PII = pair<int, int>;

const int N = 2e5 + 5;
PII a[N];


void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    PII x = a[1];
    for(int i = 2; i < m + 2; ++i){
        if(x.first <= a[i].first and x.second >= a[i].second) x = a[i];
        else if(x.first <= a[i].first and x.second <= a[i].second and a[i].first <= x.second) x = {a[i].first, x.second};
        else if(x.first >= a[i].first and x.second >= a[i].second and x.first <= a[i].second) x = {x.first, a[i].second};
        else if(x.first >= a[i].first and x.second <= a[i].second) continue;
        else goto A;
    }
    mp[x.first]++, mp[x.second + 1]--;
    A:;
    for(int i = m + 2;i <= n; ++i){
        mp[a[i].first]++;
        mp[a[i].second + 1]--;
    }
    int ans = 0;
    if(mp.empty()){
        cout << 0 << '\n';
        return;
    }
    int sum = mp.begin()->second;
    int re = mp.begin()->first;
    for(auto it = ++mp.begin(); it != mp.end(); ++it){
        if(sum > 0) ans += it->first - re;
        sum += it->second;
        re = it->first;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _;
    cin >> _;
    while(_--)solve();
    return 0;
}