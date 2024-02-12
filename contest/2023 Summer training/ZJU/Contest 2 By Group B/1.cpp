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
#define endl '\n'

const int N = 1e5 + 5;
PII a[N];

bool cmp(PII a, PII b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second > b.second;
}

bool cmp1(PII a, PII b){
    if(a.second != b.second) return a.second > b.second;
    else return a.first > b.first;
}

inline int dis(int x, int y){return x * x + y * y;}

void solve(){
    int n;
    cin >> n;
    int x = 0, y = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; ++i){
        if(dis(x + a[i].first, y + a[i].second) < dis(x - a[i].first, y - a[i].second)) x -= a[i].first, y -= a[i].second;
        else x += a[i].first, y += a[i].second;
    }
    double ans = sqrt(x * x + y * y);
    x = y = 0;
    sort(a + 1, a + 1 + n, cmp1);
    for(int i = 1; i <= n; ++i){
        if(dis(x + a[i].first, y + a[i].second) < dis(x - a[i].first, y - a[i].second)) x -= a[i].first, y -= a[i].second;
        else x += a[i].first, y += a[i].second;
    }
    ans = max(ans, sqrt(x * x + y * y));
    printf("%.8lf\n", ans);
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
