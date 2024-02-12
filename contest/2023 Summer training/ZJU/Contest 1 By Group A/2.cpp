#include<bits/stdc++.h>

using namespace std;
#define int long long 
using PII = pair<int, int>;

const int N = 2e5 + 5;
class node{
    public:
    int first, second, size;
    friend bool operator< (node a, node b){
        if(a.size != b.size) return a.size < b.size;
        else return a.first < b.first;
    }
};
node s[N];

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    map<int, int> mx;
    vector<PII>a;
    vector<node>ls;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i].first >> s[i].second;
        s[i].size = s[i].second - s[i].first;
        if(mx.count(s[i].first) and s[i].second > mx[s[i].first]) mx[s[i].first] = s[i].second;
        else if(!mx.count(s[i].first)) mx[s[i].first] = s[i].second;
    }
    for(int i = 1; i <= n; ++i){
        if(s[i].second != mx[s[i].first]) a.push_back({s[i].first, mx[s[i].first]});
        else ls.push_back({s[i].first, s[i].second, s[i].size});
    }
    sort(ls.begin(), ls.end());
    for(auto i:ls)a.push_back({i.first, i.second});
    PII x = {a[0].first, a[0].second};
    for(int i = 1; i < m + 1; ++i){
        if(x.first <= a[i].first and x.second >= a[i].second) x = {a[i].first, a[i].second};
        else if(x.first <= a[i].first and x.second <= a[i].second and a[i].first <= x.second) x = {a[i].first, x.second};
        else if(x.first >= a[i].first and x.second >= a[i].second and x.first <= a[i].second) x = {x.first, a[i].second};
        else if(x.first >= a[i].first and x.second <= a[i].second) continue;
        else goto A;
    }
    mp[x.first]++, mp[x.second + 1]--;
    A:;
    for(int i = m + 1;i < n; ++i){
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